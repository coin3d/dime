
#include <dime/entities/Entity.h>
#include <dime/Input.h>
#include <dime/Model.h>
#include <dime/State.h>
#include <dime/util/BSPTree.h>
#include <stdlib.h>

#ifdef macintosh
#include "console.h"
#include "unix.h"
#include "SIOUX.h"
#endif



class faceset_data {
public:
  faceset_data() {
  }
  ~faceset_data() {
  }
  void clean() {
    bspTree.clear();
    indices.makeEmpty();
  }
public:
  dimeArray <int> indices;
  dimeArray <int> lineIndices;
  dimeBSPTree bspTree;
}; 

// some static arrays 
static dimeArray <int> indexarray;
static dimeArray <int> tmparray;
static dimeArray <dimeVec3f> vertexarray;
static faceset_data *facesets;

static bool my_dime_callback(const dimeState * const state, 
			     dimeEntity *entity, void *);
static void convertColor(faceset_data *data, const int colnum, FILE *out);



//
//  Call this to initialize static members.
//
static void
init()
{
  if (facesets) delete [] facesets;
  facesets = new faceset_data[255];
}

//
//  Call this to free static data.
//
static void
end()
{
  delete [] facesets;
  facesets = NULL;
  indexarray.makeEmpty();
  vertexarray.makeEmpty();
}

static bool
convertDxf2Wrl(const char * const dxffilename,
	       const char * const wrlfilename)
{
  dimeInput in;
  if (!in.setFile(dxffilename)) {
    return false;
  }
  
  dimeModel model;
  if (!model.read(&in)) {
    fprintf(stderr,"Read error in line: %d\n", in.getFilePosition());
    return false;
  }

  FILE *out = fopen(wrlfilename, "w");
  if (!out) return false;
  
  fprintf(out,
	  "#VRML V1.0 ascii\n\n"
	  "Separator {\n");
  
  model.traverseEntities(my_dime_callback, &model, 
			 false, true, false);
  
  for (int i = 0; i < 255; i++) {
    convertColor(&facesets[i], i+1, out);
  }

  fprintf(out,"}\n");
  return true;
}

static void
convertColor(faceset_data *data, const int colnum, FILE *out)
{
  int i;

  int icnt = data->indices.count();
  int lcnt = data->lineIndices.count();
  int vcnt = data->bspTree.numPoints();

  if (vcnt == 0 || (icnt == 0 && lcnt == 0)) return;

  // If not present, append a -1 at the end of the index array
  if (icnt && data->indices[icnt-1] >= 0) data->indices.append(-1);
  if (lcnt && data->lineIndices[lcnt-1] >= 0) data->lineIndices.append(-1);
  
  dimeBSPTree &bsptree = data->bspTree;

  fprintf(out,"Separator {\n");

  float r, g, b;
  dimeLayer::colorToRGB(colnum, r, g, b); 

  fprintf(out,"Material {\n"
	  "diffuseColor %g %g %g\n"
	  "specularColor 1 1 1\n"
	  "}\n", r,g,b);
  
  fprintf(out,"Coordinate3 {\n"
	  "point [\n");

  int first = 1;
  for (i = 0; i < vcnt; i++) {
    dimeVec3f tmp;
    bsptree.getPoint(i, tmp);
    if (first) {
      fprintf(out,"%g %g %g", tmp[0], tmp[1], tmp[2]);
      first = 0;
    }
    else
      fprintf(out,",\n%g %g %g", tmp[0], tmp[1], tmp[2]);
  }
  
  fprintf(out,"\n]\n}\n");
  
  bsptree.clear();
  
  if (icnt) {
    fprintf(out,"IndexedFaceSet {\n"
	    "coordIndex [\n");
    int *ptr = data->indices.arrayPointer();
    int facecnt = 1;
    
    for (i = 0; i < icnt-1; i++) {
      int index = *ptr++;
      fprintf(out, "%d,", index);
      if (index < 0) {
	facecnt++;
	if ((facecnt & 3) == 0) fprintf(out,"\n"); 
      }
    }
    fprintf(out, "-1\n]\n}\n"); 
    data->indices.makeEmpty(); // free memory
  }

  if (lcnt) {
    fprintf(out,"IndexedLineSet {\n"
	    "coordIndex [\n");
    int *ptr = data->lineIndices.arrayPointer();
    int linecnt = 1;
    
    for (i = 0; i < lcnt-1; i++) {
      int index = *ptr++;
      fprintf(out, "%d,", index);
      if (index < 0) {
	linecnt++;
	if ((linecnt & 5) == 0) fprintf(out,"\n"); 
      }
    }
    fprintf(out, "-1\n]\n}\n"); 
    data->lineIndices.makeEmpty(); // free memory
  }
  

  fprintf(out,"}\n");
}


static bool
convert_noext(dimeEntity::GeometryType type, dimeBSPTree &bsp,
	      dimeArray <int> &idx,
	      dimeArray <int> &lidx,
	      const dimeMatrix &matrix,
	      const int *indices,
	      const int numidx)
{
  int i;

  switch(type) {
  case dimeEntity::POLYGONS:
    for (i = 0; i < numidx; i++) {
      int index = indices[i];
      dimeVec3f tmp = vertexarray[index];
      matrix.multMatrixVec(tmp);
      idx.append(bsp.addPoint(dimeVec3f(tmp[0], tmp[1], tmp[2])));
    }
    idx.append(-1);
    break;
  case dimeEntity::LINES:
    for (i = 0; i < numidx; i++) {
      int index = indices[i];
      dimeVec3f tmp = vertexarray[index];
      matrix.multMatrixVec(tmp);
      lidx.append(bsp.addPoint(dimeVec3f(tmp[0], tmp[1], tmp[2])));
    }
    lidx.append(-1);
    break;
  default:
    break;
  }
  return true;
}

static bool
convert_ext(dimeEntity::GeometryType type, dimeBSPTree &bsp,
	    dimeArray <int> &idx,
	    const dimeVec3f &extrusion,
	    const dimeMatrix &matrix,
	    const int *indices,
	    const int numidx)
{
  int i,index;
  
  tmparray.setCount(0);

  switch(type) {
  case dimeEntity::POLYGONS:
    for (i = 0; i < numidx; i++) {
      dimeVec3f tmp = vertexarray[indices[i]];
      matrix.multMatrixVec(tmp);
      index = bsp.addPoint(dimeVec3f(tmp[0], tmp[1], tmp[2]));
      tmparray.append(index);
      idx.append(index);
    }
    idx.append(-1);
    for (i = 0; i < numidx; i++) {
      dimeVec3f tmp = vertexarray[indices[i]];
      tmp += extrusion;
      matrix.multMatrixVec(tmp);
      index = bsp.addPoint(dimeVec3f(tmp[0], tmp[1], tmp[2]));
      tmparray.append(index);
      idx.append(index);
    }
    idx.append(-1);
    
    for (i = 0; i < numidx-1; i++) {
      idx.append(tmparray[i]);
      idx.append(tmparray[i+1]);
      idx.append(tmparray[i+1+numidx]);
      idx.append(tmparray[i+numidx]);
      idx.append(-1);
    }
    idx.append(tmparray[i]);
    idx.append(tmparray[0]);
    idx.append(tmparray[numidx]);
    idx.append(tmparray[i+numidx]);
    idx.append(-1);
    break;
  case dimeEntity::LINES:
    for (i = 0; i < numidx; i++) {
      dimeVec3f tmp = vertexarray[indices[i]];
      matrix.multMatrixVec(tmp);
      index = bsp.addPoint(dimeVec3f(tmp[0], tmp[1], tmp[2]));
      tmparray.append(index);
    }
    for (i = 0; i < numidx; i++) {
      dimeVec3f tmp = vertexarray[indices[i]];
      tmp += extrusion;
      matrix.multMatrixVec(tmp);
      index = bsp.addPoint(dimeVec3f(tmp[0], tmp[1], tmp[2]));
      tmparray.append(index);
    }
    for (i = 0; i < numidx-1; i++) {
      idx.append(tmparray[i]);
      idx.append(tmparray[i+1]);
      idx.append(tmparray[i+numidx+1]);
      idx.append(tmparray[i+numidx]);
      idx.append(-1);
    }
    break;
  default:
    break;
  }
  return true;
}


static int
get_color_index(dimeEntity *entity)
{
  int colnum = entity->getColorNumber();
  if (colnum == 256) {
    const dimeLayer *layer = entity->getLayer();
    colnum = layer->getColorNumber();
  }
  return colnum;
}

static bool 
my_dime_callback(const dimeState * const state, 
		 dimeEntity *entity, void *)
{
  if (entity->isDeleted()) return true;

  static int blockcolidx = 7;
  
  if (entity->typeId() == dimeBase::dimeBlockType) {
    blockcolidx = entity->getColorNumber();
    if (blockcolidx == 256) {
      blockcolidx = entity->getLayer()->getColorNumber();
    }
  }

  dimeMatrix matrix = state->getMatrix();
  
  indexarray.setCount(0);
  vertexarray.setCount(0);

  float thickness = 0.0;
  dimeVec3f extrusionDir(0,0,1);

  dimeEntity::GeometryType type = 
    entity->extractGeometry(vertexarray, 
			    indexarray,
			    extrusionDir,
			    thickness);
  
  if (type == dimeEntity::NONE) return true;

  // normalize data before converting
  int n = vertexarray.count();
  int numidx = indexarray.count();
 
  if (numidx == 0) {
    if (n == 0) return true; // nothing to do
    for (int i = 0; i < n; i++) indexarray.append(i);
  }
  numidx = indexarray.count();
  if (numidx && indexarray[numidx-1] >= 0) 
    indexarray.append(-1);
  
  int id = entity->typeId();

  if (id == dimeBase::dimeTraceType ||
      id == dimeBase::dimeSolidType ||
      id == dimeBase::dimeCircleType) {
    if (extrusionDir != dimeVec3f(0,0,1)) {
      dimeMatrix m;
      dimeEntity::generateUCS(extrusionDir, m);
      matrix.multRight(m);
    }
  }
  
  else if ((type == dimeEntity::POLYGONS || 
	    id == dimeBase::dimeCircleType ||
	    id == dimeBase::dimeArcType ||
	    id == dimeBase::dimeEllipseType) && 
	   (thickness == 0.0 && extrusionDir != dimeVec3f(0,0,1))) {
    dimeMatrix m;
    dimeEntity::generateUCS(extrusionDir, m);
    matrix.multRight(m);
  }
  
  int colidx = get_color_index(entity);
  
  if (colidx == 0) { // BYBLOCK
    colidx = blockcolidx;
  }
  if (colidx < 0) colidx = -colidx;
  
  colidx--; // to use lookup table 
  
  if (colidx < 0 || colidx >= 255) { // safety check
    //    sim_trace("dime color changed from %d to 6.\n", colidx, 6);
    colidx = 6; // should never happen
  }
  
  dimeBSPTree &bsp = facesets[colidx].bspTree;
  dimeArray <int> &idx = facesets[colidx].indices;
  dimeArray <int> &lidx = facesets[colidx].lineIndices;
  //  dimeArray <dimeVec3f> &pts = facesets[colidx].points;

  // FIXME: set extrusionDir to 0,0,1 ?
  extrusionDir = dimeVec3f(0,0,1);
  extrusionDir *= thickness;
  int *indices = indexarray.arrayPointer();
  numidx = indexarray.count();
  int i = 0;
  while (i < numidx) {
    int start = i;
    while (indices[i] >= 0) i++; // search for next -1
    int cnt = i-start;
    if (cnt) {
      if (thickness == 0.0) {
	convert_noext(type, bsp, idx, lidx, matrix, 
		      &indices[start], cnt);
      }
      else {
	convert_ext(type, bsp, idx, extrusionDir, 
		    matrix, &indices[start], cnt);
      }
    }
    i++; // skip -1
  }
  return true;
}



int main(int argc, char **argv)
{

#ifdef macintosh
  SIOUXSettings.asktosaveonclose = 0;
  argc = ccommand(&argv);
  _fcreator = 'CMPL';
  _ftype = 'TEXT';
#endif
  
  if (argc != 3) {
    fprintf(stderr,"Usage: dxf2wrl infile.dxf outfile.wrl\n");
  }
  else {
    init();
    if (!convertDxf2Wrl(argv[1], argv[2])) {
      fprintf(stderr,"Error while converting.\n");
    }
    end();
  }
}



