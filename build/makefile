#****************************************************************
#
# Standard makefile for DIME (non-tmake)
#
# Usage:
#	make
#
#****************************************************************

          CC = g++ -nostdinc++
          LD = ar cqs

     INCLUDE = -I../include
         OPT = -O2
       DEBUG = -DNDEBUG -D__USE_POSIX=1 -D__USE_BSD=1
     DEFINES =
        WARN =
      CFLAGS = -Wall -pedantic $(OPT) $(DEBUG) $(DEFINES) $(WARN) $(INCLUDE) -c

     COMPILE = $(CC) $(CFLAGS) $^ -o $@

     TARGETS = libdime.a

OBJECTS = \
  objs/Base.o \
  objs/Input.o \
  objs/Output.o \
  objs/Model.o \
  objs/RecordHolder.o \
  objs/Layer.o \
  objs/State.o \
  objs/Array.o \
  objs/Box.o \
  objs/BSPTree.o \
  objs/Dict.o \
  objs/Linear.o \
  objs/MemHandler.o \
  objs/Record.o \
  objs/StringRecord.o \
  objs/Int8Record.o \
  objs/Int16Record.o \
  objs/Int32Record.o \
  objs/DoubleRecord.o \
  objs/HexRecord.o \
  objs/FloatRecord.o \
  objs/Section.o \
  objs/UnknownSection.o \
  objs/EntitiesSection.o \
  objs/BlocksSection.o \
  objs/TablesSection.o \
  objs/HeaderSection.o \
  objs/ClassesSection.o \
  objs/ObjectsSection.o \
  objs/Class.o \
  objs/UnknownClass.o \
  objs/Object.o \
  objs/UnknownObject.o \
  objs/Entity.o \
  objs/UnknownEntity.o \
  objs/FaceEntity.o \
  objs/ExtrusionEntity.o \
  objs/3DFace.o \
  objs/Polyline.o \
  objs/Vertex.o \
  objs/Line.o \
  objs/Point.o \
  objs/Block.o \
  objs/Insert.o \
  objs/Solid.o \
  objs/Trace.o \
  objs/Circle.o \
  objs/Ellipse.o \
  objs/Spline.o \
  objs/Arc.o \
  objs/LWPolyline.o \
  objs/Table.o \
  objs/TableEntry.o \
  objs/UnknownTable.o \
  objs/UCSTable.o \
  objs/LayerTable.o

#***************************************************************************

all:: $(TARGETS)

clean::
	@rm -rf objs/ $(TARGETS)

objs:
	@mkdir $@

libdime.a: objs $(OBJECTS)
	$(LD) $@ $(OBJECTS)

#***************************************************************************

objs/Base.o: ../src/Base.cpp
	$(COMPILE)

objs/Input.o: ../src/Input.cpp
	$(COMPILE)

objs/Output.o: ../src/Output.cpp
	$(COMPILE)

objs/Model.o: ../src/Model.cpp
	$(COMPILE)

objs/RecordHolder.o: ../src/RecordHolder.cpp
	$(COMPILE)

objs/Layer.o: ../src/Layer.cpp
	$(COMPILE)

objs/State.o: ../src/State.cpp
	$(COMPILE)

objs/Array.o: ../src/util/Array.cpp
	$(COMPILE)

objs/Box.o: ../src/util/Box.cpp
	$(COMPILE)

objs/BSPTree.o: ../src/util/BSPTree.cpp
	$(COMPILE)

objs/Dict.o: ../src/util/Dict.cpp
	$(COMPILE)

objs/Linear.o: ../src/util/Linear.cpp
	$(COMPILE)

objs/MemHandler.o: ../src/util/MemHandler.cpp
	$(COMPILE)

objs/Record.o: ../src/records/Record.cpp
	$(COMPILE)

objs/StringRecord.o: ../src/records/StringRecord.cpp
	$(COMPILE)

objs/Int8Record.o: ../src/records/Int8Record.cpp
	$(COMPILE)

objs/Int16Record.o: ../src/records/Int16Record.cpp
	$(COMPILE)

objs/Int32Record.o: ../src/records/Int32Record.cpp
	$(COMPILE)

objs/DoubleRecord.o: ../src/records/DoubleRecord.cpp
	$(COMPILE)

objs/HexRecord.o: ../src/records/HexRecord.cpp
	$(COMPILE)

objs/FloatRecord.o: ../src/records/FloatRecord.cpp
	$(COMPILE)

objs/Section.o: ../src/sections/Section.cpp
	$(COMPILE)

objs/UnknownSection.o: ../src/sections/UnknownSection.cpp
	$(COMPILE)

objs/EntitiesSection.o: ../src/sections/EntitiesSection.cpp
	$(COMPILE)

objs/BlocksSection.o: ../src/sections/BlocksSection.cpp
	$(COMPILE)

objs/TablesSection.o: ../src/sections/TablesSection.cpp
	$(COMPILE)

objs/HeaderSection.o: ../src/sections/HeaderSection.cpp
	$(COMPILE)

objs/ClassesSection.o: ../src/sections/ClassesSection.cpp
	$(COMPILE)

objs/ObjectsSection.o: ../src/sections/ObjectsSection.cpp
	$(COMPILE)

objs/Class.o: ../src/classes/Class.cpp
	$(COMPILE)

objs/UnknownClass.o: ../src/classes/UnknownClass.cpp
	$(COMPILE)

objs/Object.o: ../src/objects/Object.cpp
	$(COMPILE)

objs/UnknownObject.o: ../src/objects/UnknownObject.cpp
	$(COMPILE)

objs/Entity.o: ../src/entities/Entity.cpp
	$(COMPILE)

objs/UnknownEntity.o: ../src/entities/UnknownEntity.cpp
	$(COMPILE)

objs/FaceEntity.o: ../src/entities/FaceEntity.cpp
	$(COMPILE)

objs/ExtrusionEntity.o: ../src/entities/ExtrusionEntity.cpp
	$(COMPILE)

objs/3DFace.o: ../src/entities/3DFace.cpp
	$(COMPILE)

objs/Polyline.o: ../src/entities/Polyline.cpp
	$(COMPILE)

objs/Vertex.o: ../src/entities/Vertex.cpp
	$(COMPILE)

objs/Line.o: ../src/entities/Line.cpp
	$(COMPILE)

objs/Point.o: ../src/entities/Point.cpp
	$(COMPILE)

objs/Block.o: ../src/entities/Block.cpp
	$(COMPILE)

objs/Insert.o: ../src/entities/Insert.cpp
	$(COMPILE)

objs/Solid.o: ../src/entities/Solid.cpp
	$(COMPILE)

objs/Trace.o: ../src/entities/Trace.cpp
	$(COMPILE)

objs/Circle.o: ../src/entities/Circle.cpp
	$(COMPILE)

objs/Ellipse.o: ../src/entities/Ellipse.cpp
	$(COMPILE)

objs/Spline.o: ../src/entities/Spline.cpp
	$(COMPILE)

objs/Arc.o: ../src/entities/Arc.cpp
	$(COMPILE)

objs/LWPolyline.o: ../src/entities/LWPolyline.cpp
	$(COMPILE)

objs/Table.o: ../src/tables/Table.cpp
	$(COMPILE)

objs/TableEntry.o: ../src/tables/TableEntry.cpp
	$(COMPILE)

objs/UnknownTable.o: ../src/tables/UnknownTable.cpp
	$(COMPILE)

objs/UCSTable.o: ../src/tables/UCSTable.cpp
	$(COMPILE)

objs/LayerTable.o: ../src/tables/LayerTable.cpp
	$(COMPILE)

