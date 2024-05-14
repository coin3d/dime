<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.10.0" doxygen_gitid="ebc57c6dd303a980bd19dd74b8b61c8f3f5180ca">
  <compound kind="class">
    <name>dime3DFace</name>
    <filename>classdime3DFace.html</filename>
    <base>dimeFaceEntity</base>
    <member kind="function">
      <type></type>
      <name>dime3DFace</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>a2c6b86f55f937fe802e696f8fddfbbb6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>a94d8d421fb20fbffa03aa211cb6da6aa</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>aa90c6befe8bc8b9581361f4728d873b0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>aada912e231d0ef55ee8d9f94990511cc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>a754b84b4fe84146117a9f31e27ebf078</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>af9f0c9f54667a188c3a5de1efa024062</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>a310f4e2044155a84336c10721aa9380c</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdime3DFace.html</anchorfile>
      <anchor>a837bb1f60d6e9201c51013d3e18a9d98</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeArc</name>
    <filename>classdimeArc.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeArc</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>a92592500b2da34d6d575a7031d3d0d0f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>a4ee3b33a69477ed3d66eb8f801a7809d</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>a25c1d50cd4304a1f24f8833df9fbf468</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>abc81ccb02080ce389cbbfa71ce1e58e7</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>a577cc8fe9d31d8bebee28fb073cb39f1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>a138aae49988c4ecc4836ac4755bc5e73</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>ad996f5da44023623510f39ebb6c1eee9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>ac8b3a4291620428f5b810dc4d4325e1e</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeArc.html</anchorfile>
      <anchor>a5489eb160ec2a2534f34c0c2b65b3c8f</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeArray</name>
    <filename>classdimeArray.html</filename>
    <templarg>class T</templarg>
    <member kind="function">
      <type>int</type>
      <name>allocSize</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a8ca927e4ea6a12978504686fb2e0128e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>arrayPointer</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>ac59a9ce50a282c6919357120a7b3dc1e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const T *</type>
      <name>constArrayPointer</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>ab2416d83c990f1fadb2644ced5d0d085</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>count</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a54a7701b4ecab42fff8f12984b5704e2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>freeMemory</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a6f5d1b4b4047077ebf37cd7a86a289cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>makeEmpty</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a2bf3a91f40f7e1034b0b7640cdb91237</anchor>
      <arglist>(const int initsize=4)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeElem</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a9a8eff67a38404cc8ddc3456d9c6d71f</anchor>
      <arglist>(const int index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeElemFast</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a5333d0fa9ab65b27de5fbe05325f84b5</anchor>
      <arglist>(const int index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCount</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>a831458028ce692871a5b8478c69012af</anchor>
      <arglist>(const int count)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>shrinkToFit</name>
      <anchorfile>classdimeArray.html</anchorfile>
      <anchor>af4b1b292d4fe1d7a077b7714b238bdcf</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeBase</name>
    <filename>classdimeBase.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeBase</name>
      <anchorfile>classdimeBase.html</anchorfile>
      <anchor>a0bdfd8bc437e82ada19130573c44cadf</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeBase</name>
      <anchorfile>classdimeBase.html</anchorfile>
      <anchor>a5001bd8f586f933a472bac5021af85f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeBase.html</anchorfile>
      <anchor>acb6386ed33ca334a16699b81299ce791</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeBase.html</anchorfile>
      <anchor>ad057cc147eddf080fa13c406ee435fa1</anchor>
      <arglist>() const =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeBlock</name>
    <filename>classdimeBlock.html</filename>
    <base>dimeEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeBlock</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a6b4a0708e8779f75afb84484d2bb4ccf</anchor>
      <arglist>(dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeBlock</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a007853663ca6a9e888fb7f9df2fbc35a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>ab6774c182ecad935bbd1dd1954bba8e7</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a9e8acd13c60dd59556a1a5344d861cfc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fitEntities</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a0f2a9736d89ac5d26f4e0d9538c09b4c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const dimeVec3f &amp;</type>
      <name>getBasePoint</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>adadf141b2613910667154ada8c785e39</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>dimeEntity *</type>
      <name>getEntity</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a63cf1403292b64747740df5a28c315b5</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a452a4bd60a7daedded99b368cabec40a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getName</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a909a3b3a5bf01a261fc0f7edee242d51</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumEntities</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a772d576799d79977a256ea3151c2fd99</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>abe30b7a755796dc88efcf9ccf4e449da</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertEntity</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a43078477c2e020a153b8de135cd14f95</anchor>
      <arglist>(dimeEntity *const entity, const int idx=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>aac41b0a9939a61cfa27de3ec0aaa21f3</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeEntity</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a807f9b0279102e54aaa87e93e149a079</anchor>
      <arglist>(const int idx, const bool deleteIt=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBasePoint</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>ab11ae897897adb642f6b3b799a64dcb4</anchor>
      <arglist>(const dimeVec3f &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a95d6c032ec0ef71666466f53e98e175c</anchor>
      <arglist>(const char *const name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>acdb24d5852f3ba38abe26765e8f30912</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a8ef6516ae91c29e5bd0161b955fdf619</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>fixReferences</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>a9f10da3a145908cf5519c10be32b880e</anchor>
      <arglist>(dimeModel *const model)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>ab24b5ddb578658850243b6f7eb96ad77</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>traverse</name>
      <anchorfile>classdimeBlock.html</anchorfile>
      <anchor>ac2346e2054a8480e8bfe99932bb95a21</anchor>
      <arglist>(const dimeState *const state, dimeCallback callback, void *userdata)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeBlocksSection</name>
    <filename>classdimeBlocksSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeBlocksSection</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>a20a2311f8721ad6c3642d5c7a5487e9a</anchor>
      <arglist>(dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeBlocksSection</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>ad9a846eea47e037fe5ae4ef296aa6ef4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>a0ab8b6707f79dfdeac166b9ffe77eff1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fixReferences</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>acceb65c2f42d356fceed002c61572535</anchor>
      <arglist>(dimeModel *const model)</arglist>
    </member>
    <member kind="function">
      <type>class dimeBlock *</type>
      <name>getBlock</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>ac71a60bc07333d1b163f47e4a3e8b00f</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumBlocks</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>aaeaf6597721b284c1c0ad819f4d24c0a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertBlock</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>a3f305c518edf72e124d10a341caa956a</anchor>
      <arglist>(dimeBlock *const block, const int idx=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>a829abe7fa8d75ecac49b5d5f6022a346</anchor>
      <arglist>(dimeInput *const file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeBlock</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>a7fc5a62272d85d1e9f7693ecf1bddbc5</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>a27ec359e5327d52a58a433103041a30c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeBlocksSection.html</anchorfile>
      <anchor>abe4bbf80bd89468f66b88e78138c745e</anchor>
      <arglist>(dimeOutput *const file)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeBox</name>
    <filename>classdimeBox.html</filename>
  </compound>
  <compound kind="class">
    <name>dimeBSPTree</name>
    <filename>classdimeBSPTree.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeBSPTree</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a8a4a6347970b1c4d846a43fe51949f6c</anchor>
      <arglist>(const int maxnodepts=64, const int initsize=4)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dimeBSPTree</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>acf185d0135a2cbedb79dbf62b2af089c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addPoint</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>ad0d00da31b467264775609b4dd818dd9</anchor>
      <arglist>(const dimeVec3f &amp;pt, void *const userdata=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>aac0def29f4206dae27438a8dddc11d7b</anchor>
      <arglist>(const int initsize=4)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>findPoint</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a48734aa4d968c1bb9ff606ef4f4d68c1</anchor>
      <arglist>(const dimeVec3f &amp;pos) const</arglist>
    </member>
    <member kind="function">
      <type>const dimeBox *</type>
      <name>getBBox</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a8f5eee9a1531065259585469147aff95</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getPoint</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a5e5090272e17672b3204cfcb4adffb20</anchor>
      <arglist>(const int idx, dimeVec3f &amp;pt)</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>getUserData</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a4fa8954956246bc3c16ad76eca34ab24</anchor>
      <arglist>(const int idx) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>numPoints</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a91dd8b6ee22050113bef33e8095f9f6a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>removePoint</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>af81f6566b1f36775556aaabfeebc6816</anchor>
      <arglist>(const dimeVec3f &amp;pt)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removePoint</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>ad84ad1eec9e4fbe59eadf2b806ef7bad</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setUserData</name>
      <anchorfile>classdimeBSPTree.html</anchorfile>
      <anchor>a6b0f0610ca9380e85d24a69d1342dc84</anchor>
      <arglist>(const int idx, void *const data)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeCircle</name>
    <filename>classdimeCircle.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeCircle</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>a088627b05fc02d41a734abcc30815b72</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>a55911a9ae6c76026b1edd90b6d5fa0c6</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>afb30eb0dfcc3bef284497e3236949adf</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>a3c76cb3276cc255243cbdba9205f998c</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>a84be2356686fbac6a8282da28daa3637</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>a60a4d704f50cf35e60f23e062517a038</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>aa6a7ac1909c3a91c49ac699efcbb8cc1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>a4c0dcdf86b649d6e8bf6f1f1690b74c0</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeCircle.html</anchorfile>
      <anchor>ab84cabbd95f7c872cce2d6563e05f74b</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeClass</name>
    <filename>classdimeClass.html</filename>
    <base>dimeRecordHolder</base>
    <member kind="function">
      <type></type>
      <name>dimeClass</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>aed373d6ca0161edbe0246afb3bdda295</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeClass</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ac85cb05eeb8d0cfbdb162927809d0bc8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual dimeClass *</type>
      <name>copy</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>afdd8c058f32e449395a20938397a1e68</anchor>
      <arglist>(dimeModel *const model) const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a27180361a87887ec3b782e64cf17fa4f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getApplicationName</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ab4a66ad8723574f460ddb32d04335c8c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getClassName</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a3f783bb7b472ee8dfa59cee85c9c70c2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const char *</type>
      <name>getDxfClassName</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a974f62808ce7dda9b6756ec173c693c6</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function">
      <type>int8</type>
      <name>getFlag280</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ac39f4f4e32515cda9d1272af1de0e5e1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int8</type>
      <name>getFlag281</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a2fa63bc06e3c2c70c7c7b5c24ce6f168</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getVersionNumber</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>adb8181c0a1977ffba53d8eea9d3358fc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ae7f774ca2aa937830fb24df1629a2275</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ad40fa3c4720589697cf1bc01e78c248c</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setApplicationName</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a6abe94d42d4203de49e2c50d1a17d76a</anchor>
      <arglist>(const char *const appname, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setClassName</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ab60a515dbcaf8857cec46471a2df7e5e</anchor>
      <arglist>(const char *const classname, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFlag280</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>ad746ac0304f7eac8f26fa6f122897e78</anchor>
      <arglist>(const int8 flag)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFlag281</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a61c7627272a74bc135b8bb73188c46f5</anchor>
      <arglist>(const int8 flag)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setVersionNumber</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a0ee172050d4abc5519b85c0dc39d6d82</anchor>
      <arglist>(const int32 v)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>af08b817a7a200fbc2a9621f41427189b</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeClass *</type>
      <name>createClass</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a55dd35b5ba76dff875f38804f78617c4</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>copyRecords</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a4bc9ac9b99bc4bbce3f76d356dd6ddf2</anchor>
      <arglist>(dimeClass *const newclass, dimeModel *const model) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeClass.html</anchorfile>
      <anchor>a0adccbf899c415143bd4514c0270fffc</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeClassesSection</name>
    <filename>classdimeClassesSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeClassesSection</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>aa6ab426a21bc06224e91bd7db9811e3b</anchor>
      <arglist>(dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeClassesSection</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>ab4479dcb8c75b33ed35203b98ab64b14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>a89bbf0249f36023862ebf84b063d3386</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>class dimeClass *</type>
      <name>getClass</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>ae8246f07c59395e4e275e99eea45f17d</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumClasses</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>aa5d057f6bd6b7d0e21355263be132bdb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertClass</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>ab715c69eef0014439247344d99d31b27</anchor>
      <arglist>(dimeClass *const myclass, const int idx=-1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeClass</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>acb1ddbde059a15513f1852033fbcf877</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeClassesSection.html</anchorfile>
      <anchor>a615870dc58f2d6aeb33ba76872014a4d</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeDict</name>
    <filename>classdimeDict.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeDict</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>afdaae8a74c2fa3eb52e4e2316babca83</anchor>
      <arglist>(const int entries=17989)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dimeDict</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>a5dc67b83d3bd3932b157fc9685785c40</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>a2eb6a6c1309f23e216b34156bd0d322c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>enter</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>a3090243d740d19e73b80843886c0f89e</anchor>
      <arglist>(const char *const key, char *&amp;ptr, void *value)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>enter</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>a83c21176219f3f1e554ee9275be6a140</anchor>
      <arglist>(const char *const key, void *value)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>find</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>a2447035b6f34c185a194f49b70812a49</anchor>
      <arglist>(const char *const key) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>find</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>ace0354b68e5cd6e689bb18f51e2f4cf6</anchor>
      <arglist>(const char *const key, void *&amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>remove</name>
      <anchorfile>classdimeDict.html</anchorfile>
      <anchor>acb59b1f617457186902ea9045f56cafe</anchor>
      <arglist>(const char *const key)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeDictEntry</name>
    <filename>classdimeDictEntry.html</filename>
  </compound>
  <compound kind="class">
    <name>dimeDoubleRecord</name>
    <filename>classdimeDoubleRecord.html</filename>
    <base>dimeRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeDoubleRecord</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>a580652ef9eb1913590d2a1cbebb42334</anchor>
      <arglist>(const int group_code=10, const dxfdouble val=0.0f)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>a26c5065e2da09e16ab8372e1e67a0bce</anchor>
      <arglist>(dimeMemHandler *const mh) const</arglist>
    </member>
    <member kind="function">
      <type>dxfdouble</type>
      <name>getValue</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>adc95d9aa581630bc26a37fb8197fc523</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>ad924b1248a4f014f8f9a1091e6c63cf8</anchor>
      <arglist>(dimeParam &amp;param) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>a0e6f64b85c986bce7d861805c6e5c5eb</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>ae8547e028feb190f2387040984f1bfb7</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setValue</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>a8d87b271b889c565c336871a50ce06fa</anchor>
      <arglist>(const dxfdouble val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>a3c7dd2ce83fc632bc16c47e608299e9c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeDoubleRecord.html</anchorfile>
      <anchor>a97d3b8a09c9e7e3873a36e3dfa6af2fa</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeEllipse</name>
    <filename>classdimeEllipse.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeEllipse</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a4beebd80676d883b5ac8595cb9778d96</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a6d9722acf5c70744dfcea226f0bbf64a</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>ad027329d949d208c4251c52c22c1665f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const dimeVec3f &amp;</type>
      <name>getCenter</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>ae105d31a7cd395de38ea37822868290c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>dxfdouble</type>
      <name>getEndParam</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a3e1c6353f7128bd368b05dffd10819b2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a76bef2a3d3fdd17bf8b314112127a394</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const dimeVec3f &amp;</type>
      <name>getMajorAxisEndpoint</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a75bad935f4c2d5a33c89dd3ae2206aa2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>dxfdouble</type>
      <name>getMinorMajorRatio</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a1442172cd0eb8b5b3ae2eace6c6c2df7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a71ee444212ec48ae07f44194b2b0b1e0</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>dxfdouble</type>
      <name>getStartParam</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a75f10133d71a03031bc452a3934e020c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCenter</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a049e84b211dc05f86922075125277356</anchor>
      <arglist>(const dimeVec3f &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEndParam</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>ae2804ba4a7a846b8db575ee0812aeff0</anchor>
      <arglist>(const dxfdouble p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMajorAxisEndpoint</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a023d2259d6ff56ba511de3b3fbf82a55</anchor>
      <arglist>(const dimeVec3f &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMinorMajorRatio</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a6cb1cfcc9abc6a75e30700cc1a41d21d</anchor>
      <arglist>(const dxfdouble ratio)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStartParam</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>aba2f78ff68634333d2299fc210217ddc</anchor>
      <arglist>(const dxfdouble p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>a3b6e4ef97c404ad73419808fc66ab05d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>afb9e024d1b0fb8eb56e2a40ba2d9ae01</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeEllipse.html</anchorfile>
      <anchor>ad9a3ec499133802e61fb0de60b2efb61</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeEntitiesSection</name>
    <filename>classdimeEntitiesSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeEntitiesSection</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a1c13365357cb59eb82a955b067f232f7</anchor>
      <arglist>(dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeEntitiesSection</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a0e69f29f0a9e231602674fd6159de23c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a751cbaaa463ff8b5533cc4be81a39a94</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fixReferences</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a8c849d810c9fe305b5645da1a6efbf3e</anchor>
      <arglist>(dimeModel *const model)</arglist>
    </member>
    <member kind="function">
      <type>dimeEntity *</type>
      <name>getEntity</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>ac996bb421ecfe8929476b88c351fd276</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumEntities</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a4f0941b75dff5c41a298f9c6a7ce24f4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertEntity</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a6fbffd978308007551afd8d9a0fbbef3</anchor>
      <arglist>(dimeEntity *const entity, const int idx=-1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeEntity</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>a51a1040471115fbc9da032f13351a8e8</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeEntitiesSection.html</anchorfile>
      <anchor>ae82bf6c842d839e3d3e4f9dbfaef59fe</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeEntity</name>
    <filename>classdimeEntity.html</filename>
    <base>dimeRecordHolder</base>
    <member kind="function">
      <type></type>
      <name>dimeEntity</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a5f6b0f33bfdde28f17bb3fe001e6f725</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeEntity</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a5095f58c30117c1f5d0e048d49c8131a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>ade9976689eef5a106703766adfb646e5</anchor>
      <arglist>(dimeModel *const model) const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>aad083ff37e62b1fefb2c884c2bb943e4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>ac05ceb27ce59e88f616b2d6e29cc965b</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function">
      <type>int16</type>
      <name>getColorNumber</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>afacc4f7d7702a5ee1e764f778be90940</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>aa76ebb5f27452e91bb9a220a38c6a622</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function">
      <type>const dimeLayer *</type>
      <name>getLayer</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a8d914685ee4b6a85670a773f378e2102</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getLayerName</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a644834f5cff11a5b3124aeda21c0e3ee</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a19c366ca24c548666a49179bc15de2bc</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDeleted</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a7d3213612a802ef390a6b75228bf080a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a9e8639c359d924982edbf5a4a8d2d9a5</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTagged</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a1826a9bca63fa24a75016adb55f702ac</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a52e0071cb051b5fd835b3dedde8450a4</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColorNumber</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>aac63aef1deb41f560fc382c35ef9f151</anchor>
      <arglist>(const int16 c)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDeleted</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a533ca05437ed357ed158a3059e4ccc6a</anchor>
      <arglist>(const bool onOff=true)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setLayer</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>aa19112c167d39de5a3a1deb5cd3f175c</anchor>
      <arglist>(const dimeLayer *const layer)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTagged</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>ac68d942de5657a2eee5c8f969e417f45</anchor>
      <arglist>(const bool onOff=true)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a46f9e218012c5253e116e8048a51d499</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>arbitraryAxis</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a2603013684401c821009ebc3b27ae40b</anchor>
      <arglist>(const dimeVec3f &amp;givenaxis, dimeVec3f &amp;newaxis)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>copyEntityArray</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>ad707eaea7c92e766ca5c772b67b5a362</anchor>
      <arglist>(const dimeEntity *const *const array, const int nument, dimeModel *const model, dimeArray&lt; dimeEntity * &gt; &amp;destarray)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeEntity **</type>
      <name>copyEntityArray</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>ada0f01b1ce684f0977beef001b82ba4b</anchor>
      <arglist>(const dimeEntity *const *const array, int &amp;nument, dimeModel *const model)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeEntity *</type>
      <name>createEntity</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a31a96ce7af911c6aa942af0d994bf871</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>generateUCS</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a46d020a97b0b72c730fa7f5a2000723f</anchor>
      <arglist>(const dimeVec3f &amp;givenaxis, dimeMatrix &amp;m)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>readEntities</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a4a8b0c9afd9ec866b08c7e2c6de9de8e</anchor>
      <arglist>(dimeInput *const file, dimeArray&lt; dimeEntity * &gt; &amp;array, const char *const stopat)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>copyRecords</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a437e2d853eaae52179cf56211bd9461b</anchor>
      <arglist>(dimeEntity *const entity, dimeModel *const model) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>fixReferences</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a4cb3a8e236ff7e93ab10757f8bc776f6</anchor>
      <arglist>(dimeModel *const model)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>abd559e5cb6d05a244af781fbc6a2f744</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>preWrite</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>a0dd95716e0668d314d3b36c652f737aa</anchor>
      <arglist>(dimeOutput *const file)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>shouldWriteRecord</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>abde0304c0ceb244d70a802875ccb1dd6</anchor>
      <arglist>(const int groupcode) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>traverse</name>
      <anchorfile>classdimeEntity.html</anchorfile>
      <anchor>aff18feb31887bb953385d69dc5af0d62</anchor>
      <arglist>(const dimeState *const state, dimeCallback callback, void *userdata)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeExtrusionEntity</name>
    <filename>classdimeExtrusionEntity.html</filename>
    <base>dimeEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeExtrusionEntity</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>a6481d61d3ce25de8bbf8014b760d2e8c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>adad1718bd9a87b463de1e9fedea3b71b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const dimeVec3f &amp;</type>
      <name>getExtrusionDir</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>a8d736f6621ff9e324b38255b1d74c187</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>af3596428241f800cf6923839fe4b7fe1</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>dxfdouble</type>
      <name>getThickness</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>ae1bb32ded9b589864ed80e54be8d8921</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>a76c363baaa54090963e02738873df61d</anchor>
      <arglist>(const int thtypeid) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setExtrusionDir</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>ad30820790b9f22a41d55689c12eb217a</anchor>
      <arglist>(const dimeVec3f &amp;v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setThickness</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>ac5d82f1613074857452463ad9be238f1</anchor>
      <arglist>(const dxfdouble val)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>ac53045af8b047350defc82054e327b3f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>copyExtrusionData</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>ad05015f57a6c37bd715cbd319ecb4909</anchor>
      <arglist>(const dimeExtrusionEntity *const entity)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>a140dacd6717f3de19d90f2a8ff1296dd</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>writeExtrusionData</name>
      <anchorfile>classdimeExtrusionEntity.html</anchorfile>
      <anchor>a059d8c094e2881b6550696ef4b4d7d19</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeFaceEntity</name>
    <filename>classdimeFaceEntity.html</filename>
    <base>dimeEntity</base>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>ae5e83ea2c4ca082559b25fcff75ea87f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a59ae2f06d88465e2de26cb6db937afa7</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getExtrusionDir</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>aa7b1943e3266a0b6d95dd66b3a3464d3</anchor>
      <arglist>(dimeVec3f &amp;ed) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a24509a15b26ed8acefb239112f261005</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dxfdouble</type>
      <name>getThickness</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>ac52083c77d516ed82cdee39d65e302b3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const dimeVec3f &amp;</type>
      <name>getVertex</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>af718c20a5e343786dac24ecf4d4c44be</anchor>
      <arglist>(const int idx) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>getVertices</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a9e00b37334011b74151129f58fdaf23f</anchor>
      <arglist>(dimeVec3f &amp;v0, dimeVec3f &amp;v1, dimeVec3f &amp;v2, dimeVec3f &amp;v3) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a610b0bddfb4856c4152ce584e8fe355f</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setQuad</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a0f8d0b701be2c7ffae19aef40d53b456</anchor>
      <arglist>(const dimeVec3f &amp;v0, const dimeVec3f &amp;v1, const dimeVec3f &amp;v2, const dimeVec3f &amp;v3)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTriangle</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a78b7a7aa836ee6ee05a20671f2c8493d</anchor>
      <arglist>(const dimeVec3f &amp;v0, const dimeVec3f &amp;v1, const dimeVec3f &amp;v2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>aa207d1a898ff48b24fa059be351fcab6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>copyCoords</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>adeafc7a03818efd761746a6f63cda674</anchor>
      <arglist>(const dimeFaceEntity *const entity)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a6cf0d88764a1068156ade4643a1c6fd5</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>swapQuadCoords</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a26a305681152205c5bd293ecc1616f15</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>writeCoords</name>
      <anchorfile>classdimeFaceEntity.html</anchorfile>
      <anchor>a1acfbe98d941cc8d75916220448fc682</anchor>
      <arglist>(dimeOutput *const file)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeFloatRecord</name>
    <filename>classdimeFloatRecord.html</filename>
    <base>dimeRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeFloatRecord</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>ae7800d3786903ae769e4a24864b9da46</anchor>
      <arglist>(const int group_code=10, const float val=0.0f)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a14a92562d81e82a4f3eee9a4baa992c7</anchor>
      <arglist>(dimeMemHandler *const mh) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a1541f57fcd43f95f60ee2c020f94f1a0</anchor>
      <arglist>(dimeParam &amp;param) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a7986bd5c12772e1077c154e7091c9312</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a27716eb3189b8ade06973af8af9389bf</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setValue</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a88b2f955cac403a8fa8f05070d204456</anchor>
      <arglist>(const float val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a9be383857c914eb1b60bcff93be93896</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeFloatRecord.html</anchorfile>
      <anchor>a2af57c6b3bda5c5c6a075806853c0853</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeHeaderSection</name>
    <filename>classdimeHeaderSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeHeaderSection</name>
      <anchorfile>classdimeHeaderSection.html</anchorfile>
      <anchor>aad38f03833268ae8881556191cc004d4</anchor>
      <arglist>(dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeHeaderSection</name>
      <anchorfile>classdimeHeaderSection.html</anchorfile>
      <anchor>a0c3ab5bc8c44304af5d32be76297f6cf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeHeaderSection.html</anchorfile>
      <anchor>adeb601b6aaadc5894063a96f257229e7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getVariable</name>
      <anchorfile>classdimeHeaderSection.html</anchorfile>
      <anchor>af704fc9c90a7d4739e728971592607cb</anchor>
      <arglist>(const char *const variableName, int *const groupcodes, dimeParam *const params, const int maxparams) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>setVariable</name>
      <anchorfile>classdimeHeaderSection.html</anchorfile>
      <anchor>ae2a364e84e6c0eb3fb0bb567abdadcd0</anchor>
      <arglist>(const char *const variableName, const int *const groupcodes, const dimeParam *const params, const int numparams, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeHeaderSection.html</anchorfile>
      <anchor>adcf29a17727e282ac78f0f06e9ece2fc</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeHexRecord</name>
    <filename>classdimeHexRecord.html</filename>
    <base>dimeStringRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeHexRecord</name>
      <anchorfile>classdimeHexRecord.html</anchorfile>
      <anchor>a7e996a33517419ec5921a3f5c122ad0d</anchor>
      <arglist>(const int group_code=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeHexRecord.html</anchorfile>
      <anchor>a9b5714a3803bb0e14a3d8cc8e0022055</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeInput</name>
    <filename>classdimeInput.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeInput</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>ab06fa7de567b7a5e1a635f90e882084d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dimeInput</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a768660b8b3f804109411d36e84847ba8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>eof</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a5cd61f0c9c24011adc97f104cadae8a4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getFilePosition</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a3ec3cc96f3027ce7c76df370457c7e1d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>class dimeMemHandler *</type>
      <name>getMemHandler</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a9b69a424226e31a4810bed06dabe59de</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>class dimeModel *</type>
      <name>getModel</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a049b18e2635104255b270b12b05122df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getVersion</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a340d9f1c2576770043d96a8913530b3d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isAborted</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a3e532347ff2c29e944ddc5ffd60da105</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBinary</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a65103f1fbd1e7baf7d3c7eadd8aa2741</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>putBackGroupCode</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a173233ed45f35222514efb33233cb5b0</anchor>
      <arglist>(const int32 code)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readDouble</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a21d6840c291c2e5e39586921df413997</anchor>
      <arglist>(dxfdouble &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readFloat</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a2096a98d3a435e6a3be917bbae675d34</anchor>
      <arglist>(float &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readGroupCode</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>aee6ef945760775f72261f8be35a28aef</anchor>
      <arglist>(int32 &amp;code)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt16</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>aa2ea6336fee3005f2a4be7b65abe909e</anchor>
      <arglist>(int16 &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt32</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a01a8a3e007edde0c3cec72ab75f9d108</anchor>
      <arglist>(int32 &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt8</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>ab88cfeab1f48775b8dd1b6ad7a71f11f</anchor>
      <arglist>(int8 &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>readString</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a153ce3568e89d051b07365871d4f9ced</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>readStringNoSkip</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>ac0facba89a3398698c9f31b97f9d61cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>float</type>
      <name>relativePosition</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>ae18e64d9470ffd103ac6e08b869ba396</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCallback</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a43fa207d756d4cebb246153e66917e37</anchor>
      <arglist>(int(*cb)(float, void *), void *cbdata)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFile</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a261d3962cec05f30f91703c2fea7e535</anchor>
      <arglist>(const char *const filename)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFileHandle</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>af67af1bf8b60eea7b86ec7c922a78c9e</anchor>
      <arglist>(FILE *fp)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFilePointer</name>
      <anchorfile>classdimeInput.html</anchorfile>
      <anchor>a4b8e06be0c37933e2db4ac9f043a5440</anchor>
      <arglist>(const int fd)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeInsert</name>
    <filename>classdimeInsert.html</filename>
    <base>dimeEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeInsert</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a926e5f145896bcdabe6ab64b00394843</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeInsert</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>ae4744d3cf36d42343e23fd887935ac62</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>af6c9e1767df731ba7a380210ee0b7059</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a85deeaa11dc5173c59f88497876a0cb6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a2ac06fba7b65f9f0d09f6c35d239799d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a37b70067f656fe006f2346eef3981616</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a1b9c9baae9eef9f83b10fadd67152efc</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBlock</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>ab358873c55e03de1052bd2c8cd9023af</anchor>
      <arglist>(dimeBlock *const block)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a05328b05f6071fb9db26d21add320062</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a0fe44d100190cad07576db703df010f7</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>fixReferences</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a72a42646e71f60f9c1970fc13fb47847</anchor>
      <arglist>(dimeModel *const model)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>add0bf71ba851683133209f84f04b828c</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>traverse</name>
      <anchorfile>classdimeInsert.html</anchorfile>
      <anchor>a49b0ae0f14d3b715961c4ecd4b4c0103</anchor>
      <arglist>(const dimeState *const state, dimeCallback callback, void *userdata)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeInt16Record</name>
    <filename>classdimeInt16Record.html</filename>
    <base>dimeRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeInt16Record</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>af09a9e244e5cc3ccd55125d6f815c32a</anchor>
      <arglist>(const int group_code=60, const int16 val=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>a922eea6c377e3c15bd4e409cf95da9ac</anchor>
      <arglist>(dimeMemHandler *const mh) const</arglist>
    </member>
    <member kind="function">
      <type>int16</type>
      <name>getValue</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>a3d430863d653dc0b3245fce9fdaf4037</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>a3382ebd2853c38177ab8841c68365434</anchor>
      <arglist>(dimeParam &amp;param) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>a3b626c90c0aa1254f056fd21c029940a</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>a81e988e67289af4c00cc0b561b2e9bdf</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setValue</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>aa671a15aec273705ebd8289d550b20ad</anchor>
      <arglist>(const int16 val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>aa1e41e6dd98861d6c759985d743e7733</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeInt16Record.html</anchorfile>
      <anchor>ab7cdfc5f1bde4a96bf28faefabb27ed8</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeInt32Record</name>
    <filename>classdimeInt32Record.html</filename>
    <base>dimeRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeInt32Record</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>aba6b6686c1080907e0346734fff59079</anchor>
      <arglist>(const int group_code=90, const int32 val=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>ae5a8cddbb7eaf06ecc0302cb537f72d8</anchor>
      <arglist>(dimeMemHandler *const mh) const</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getValue</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>a2a1dfeedc5378ce9d265f5f87e1b44aa</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>aca75694da2608f457ca61200e37b0111</anchor>
      <arglist>(dimeParam &amp;param) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>a4a13148aeeece1c778194d9ca748c596</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>a518938da1dd721a19ace86b4355cd614</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setValue</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>a32685b9b404ac43c6c54c69cefab2f70</anchor>
      <arglist>(const int32 val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>af0d5b451b390938c5c2ee097745ebec4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeInt32Record.html</anchorfile>
      <anchor>a0fbd2e001e741195d3902fc5f0acd2c5</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeInt8Record</name>
    <filename>classdimeInt8Record.html</filename>
    <base>dimeRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeInt8Record</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>adf725d905dd9f3a200096a72b098e44a</anchor>
      <arglist>(const int group_code=270, const int8 val=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>a9857bbc65a1beb76227735d97ecfc0bc</anchor>
      <arglist>(dimeMemHandler *const mh) const</arglist>
    </member>
    <member kind="function">
      <type>int8</type>
      <name>getValue</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>ae68bbbb02a3d046d08986e021534fafb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>ac213ccb182413a5b73c7d7e56fd3d3b8</anchor>
      <arglist>(dimeParam &amp;param) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>a0e3a32a0e954797e3c5750d8c1d1b9c5</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>a08c0a8f80c335eaa991624964250d4a2</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setValue</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>a8312a71c450f27e4cde7e8cc7e2d2c60</anchor>
      <arglist>(const int8 val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>a098f0ef4579d59610b4b6d3e8053e059</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeInt8Record.html</anchorfile>
      <anchor>ac609e880c15913a9509f7e3a35f91106</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeLayer</name>
    <filename>classdimeLayer.html</filename>
    <member kind="function">
      <type>int16</type>
      <name>getColorNumber</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a5c1184e052fa0cc6a6467362ad742050</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int16</type>
      <name>getFlags</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a3376cfb7f84f07c738cec1a65a598206</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getLayerName</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a5327ecca85ce4457324abdcabb798642</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getLayerNum</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a355746acbb7ebf388ec4e0c01dbffc90</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDefaultLayer</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a47e5074b30994de42197f6b5964b509a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColorNumber</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a7c226da63bc2a75769f5e7f867b40326</anchor>
      <arglist>(const int16 num)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFlags</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>a4bed9c3a486f25c8fc1a83e7edf3c0ee</anchor>
      <arglist>(const int16 &amp;flags)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const dimeLayer *</type>
      <name>getDefaultLayer</name>
      <anchorfile>classdimeLayer.html</anchorfile>
      <anchor>ac032d8c3bc5d697fb663cb22db421a76</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeLayerTable</name>
    <filename>classdimeLayerTable.html</filename>
    <base>dimeTableEntry</base>
    <member kind="function">
      <type></type>
      <name>dimeLayerTable</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a05ffd4b924bc71d5a4e6ce4e776225cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a45f369e57f881c3c25d2234ccb63ae5e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int16</type>
      <name>getColorNumber</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a961cf887fb3be87767ed991f274dd45d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getLayerName</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a4b29d52055e77cd33e050b960b88ba82</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a4a8f02f088bc92877b0c47060206f2de</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>registerLayer</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>ad9aaa39b7f95e302ae1014a50a419596</anchor>
      <arglist>(dimeModel *model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColorNumber</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a2409288004464fa9fb662bdd5ba17963</anchor>
      <arglist>(const int16 colnum)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLayerName</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a2dcf38643275b39ca49167e0745c49a5</anchor>
      <arglist>(const char *name, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>aabcfb4fd6ff81c8aaa893283ac629526</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>ae95ecabc817f5b4d4750336b61d21ab5</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeLayerTable.html</anchorfile>
      <anchor>a5ba34429f79eae7ffde643bbad0c24a1</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeLine</name>
    <filename>classdimeLine.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeLine</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>a6d3b40d56acb9e2746de02fafabbf531</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>abdfb09bdb719c8065aae25ea9efc0394</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>aaabadece7a362fe18f0c5dbd94ed07a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>ad65a75b931e34e018eb38f93b72bba92</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>adc5df3fe753a1d8d0f2aa08d41ef928d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>a7e08a94beef995684915c2ed40f52908</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>ab6c4c5ac3956cff285b8979be0d7f372</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>a1d6f36a01c245cfbe9fe91e5ef19c94b</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeLine.html</anchorfile>
      <anchor>a6a67956784e43164f67d91f41fedf72d</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeLWPolyline</name>
    <filename>classdimeLWPolyline.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeLWPolyline</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>a82f91e3936c36a5b8bc62151ecd7d9d7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeLWPolyline</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>abc7314c365dbaf984efbc37ab1501648</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>a156e50bc6e4dba224114ff3d3ad52d32</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>aeb9f6c993340091d594218bf2f8b5af1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>a5fcb4c64160e8f15a9fbc2be70c55e65</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>ac341b9f204dc3eeaaccf6148589a1a4c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>a1503a78a2e4f1b961a19f98f70969979</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>ae65663a2f4eb39e521aae3767cdf384a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>ada7b11fbfb17596cb17e87c379f74325</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeLWPolyline.html</anchorfile>
      <anchor>af95a26902620ea742830b727f2ea5f97</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeMatrix</name>
    <filename>classdimeMatrix.html</filename>
  </compound>
  <compound kind="class">
    <name>dimeMemHandler</name>
    <filename>classdimeMemHandler.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeMemHandler</name>
      <anchorfile>classdimeMemHandler.html</anchorfile>
      <anchor>a56a3422d86987c394d48f57b8db0a56a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dimeMemHandler</name>
      <anchorfile>classdimeMemHandler.html</anchorfile>
      <anchor>a6f3e0e6b84a203af291245a5b1441dd4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>allocMem</name>
      <anchorfile>classdimeMemHandler.html</anchorfile>
      <anchor>a3e182a4729f26837c844bdfc7e1b55fa</anchor>
      <arglist>(const int size, const int alignment=4)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>initOk</name>
      <anchorfile>classdimeMemHandler.html</anchorfile>
      <anchor>ae9274e0cb62fe6acab11af5fedcaba77</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>stringAlloc</name>
      <anchorfile>classdimeMemHandler.html</anchorfile>
      <anchor>a672ff4d701674911bec8b660f1783afb</anchor>
      <arglist>(const char *const string)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeModel</name>
    <filename>classdimeModel.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeModel</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>addcd4755a0eb3443e414e2b4a4833430</anchor>
      <arglist>(const bool usememhandler=false)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dimeModel</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a01776cdda6edae951c4e0a0a5c29a8f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>addBlock</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>afe555a75881e4800d54d9c3cda49c7ad</anchor>
      <arglist>(const char *const blockname, dimeBlock *const block)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addEntity</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ad18e7b317b6151a2f0b09ec28499a43f</anchor>
      <arglist>(dimeEntity *entity)</arglist>
    </member>
    <member kind="function">
      <type>const class dimeLayer *</type>
      <name>addLayer</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a9c3cc1dda8637364cd8c91abaa570718</anchor>
      <arglist>(const char *const layername, const int16 colnum=7, const int16 flags=0)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>addReference</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ac1cf63deced269303c96cea103419070</anchor>
      <arglist>(const char *const name, void *id)</arglist>
    </member>
    <member kind="function">
      <type>dimeModel *</type>
      <name>copy</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ab6fb494e1ec44a0cc5648c17df95ef7c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>countRecords</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a06ed10cba87619c204a0cda74576fb2d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>class dimeBlock *</type>
      <name>findBlock</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ab17fbd9de7656355b912499998ab1f46</anchor>
      <arglist>(const char *const blockname)</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>findReference</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a3fe41cc73da323c9d46074a01219ac9b</anchor>
      <arglist>(const char *const name) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>findRefStringPtr</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a0a835f5b3b95e8fe2d89fe9109d94975</anchor>
      <arglist>(const char *const name) const</arglist>
    </member>
    <member kind="function">
      <type>class dimeSection *</type>
      <name>findSection</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a3d21932b183ff556c3d255c7c109e875</anchor>
      <arglist>(const char *const sectionname)</arglist>
    </member>
    <member kind="function">
      <type>const class dimeSection *</type>
      <name>findSection</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>adba52b121c722b79a6418267e3a1b25f</anchor>
      <arglist>(const char *const sectionname) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getDxfVersion</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ab8fdb56db5af3e7053aee1f23e386413</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const class dimeLayer *</type>
      <name>getLayer</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a4955261740c3a9ce551c50b53abc93eb</anchor>
      <arglist>(const char *const layername) const</arglist>
    </member>
    <member kind="function">
      <type>const class dimeLayer *</type>
      <name>getLayer</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ad4c084a57d9f97b82cbe147ce0f728a1</anchor>
      <arglist>(const int idx) const</arglist>
    </member>
    <member kind="function">
      <type>class dimeMemHandler *</type>
      <name>getMemHandler</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ae77f64bbe4f164673b78e14b2dc56cfe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumLayers</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a8804a68876e00d428bdb6c25a752bef3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumSections</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a7a0e7edad087bc38602b90a635a5970f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>class dimeSection *</type>
      <name>getSection</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a2ca8f42ef9d45b161edca47452c65688</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>init</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a694b527c3e50ad71e8f730ecf1995343</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertSection</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a6ae45881a20d6e906b223ba8a4ce2265</anchor>
      <arglist>(dimeSection *const section, const int idx=-1)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>ac2c5c3f7f565a71e333b34ede26f1e3a</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>registerHandle</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a70c23ab97729f313e247044cb3aeb475</anchor>
      <arglist>(const char *const handle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>registerHandle</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a46326883d3974046047c39ee522016ac</anchor>
      <arglist>(const int handle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeReference</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a65587b9b074df1ae15510bf7652ec2fa</anchor>
      <arglist>(const char *const name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeSection</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>acdd3c1eaa304606154d9f637efc4bf46</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>traverseEntities</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a22ff66c23610384c1e8fd16286496eca</anchor>
      <arglist>(dimeCallback callback, void *userdata=NULL, bool traverseBlocksSection=false, bool explodeInserts=true, bool traversePolylineVertices=false)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a5055905c82d651855c00c04d5daf8cb6</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const char *</type>
      <name>getVersionString</name>
      <anchorfile>classdimeModel.html</anchorfile>
      <anchor>a8815053638df2e9e4be262708575fe3a</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeObject</name>
    <filename>classdimeObject.html</filename>
    <base>dimeRecordHolder</base>
    <member kind="function">
      <type></type>
      <name>dimeObject</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>ac2eeaaf13c4efec2b7a2f8df09442322</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeObject</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>acc8105614e70e3c16e872fd8f673b1e0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>ad4cc32f9d95117c455c124c3ccba506c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>a02f0581c42f2c81cf9f0996e51962ce7</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>af7d239c43b33dc09851c773a0cd411f2</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>abb385d72ae91b77f5cd579b49c756252</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>ae68a5dd2d8eeb19a4939b62154d4c9fd</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeObject *</type>
      <name>createObject</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>a6ff6448608fda979b46881da56714c7f</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>copyRecords</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>a877c57c5dd0b59cf0d37fc34a6fc347c</anchor>
      <arglist>(dimeObject *const newobject, dimeModel *const model) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeObject.html</anchorfile>
      <anchor>aedb222859c8861f732c80d0512e3eb0f</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeObjectsSection</name>
    <filename>classdimeObjectsSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeObjectsSection</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>acafc9f021285f0ebbbd14550065287ac</anchor>
      <arglist>(dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeObjectsSection</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>a858fcca0d12fb72b7fd5a2ff5bc35908</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>a87b8dbf56bc74f3265f4d5c5bd6f3d04</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumObjects</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>afd1abc561b3f1cac53bbd3b7c878f2d6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>class dimeObject *</type>
      <name>getObject</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>a0b97b82fda7312923de8e98f0023f1e9</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertObject</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>a6b5081557bc962f812865c3cad52061e</anchor>
      <arglist>(dimeObject *const object, const int idx=-1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeObject</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>a21d43f1ac202cd167473b18212e342ab</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeObjectsSection.html</anchorfile>
      <anchor>a507c42562776f25c152a447ae033e546</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeOutput</name>
    <filename>classdimeOutput.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeOutput</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>acf8f7b0617099f6aeca1f7fc54063ee3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dimeOutput</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>ae9095fa9d8004b1b5063c55d48138314</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBinary</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>addc78d700ed50c3d2a462ec86d830095</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBinary</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>ab113b12be80f7b3610d8e511969bc172</anchor>
      <arglist>(const bool state=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCallback</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>ab37ec496920cfc10effcba169da56faa</anchor>
      <arglist>(const int numrecords, int(*cb)(float, void *), void *cbdata)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFileHandle</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>a541051fe60091bf1cb44ba24eb68c8b4</anchor>
      <arglist>(FILE *fp)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFilename</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>a90bbb64b878bec76318cc25df7bd6a8e</anchor>
      <arglist>(const char *const filename)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeDouble</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>ac5cb1196633183139981df3c1f95b639</anchor>
      <arglist>(const dxfdouble val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeFloat</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>aa9435ee03c1794d36a90b5ba363a6813</anchor>
      <arglist>(const float val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeGroupCode</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>a0f59c6d325880f60c9754e4ed23d3749</anchor>
      <arglist>(const int groupcode)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeHeader</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>a4b2d1bbf49b8932f031b49391e7c5f1b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt16</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>abeaa3dafc10cc5bc9ca2a0b8ab12b317</anchor>
      <arglist>(const int16 val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt32</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>a5f987908e9ba564efd8242d355bdf8ee</anchor>
      <arglist>(const int32 val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt8</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>ac085fce4178e3bcd32b634e46fd70fc0</anchor>
      <arglist>(const int8 val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeString</name>
      <anchorfile>classdimeOutput.html</anchorfile>
      <anchor>a0cd6b0eacb5231a1312b8797e4f3b1d6</anchor>
      <arglist>(const char *const str)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeParam</name>
    <filename>uniondimeParam.html</filename>
  </compound>
  <compound kind="class">
    <name>dimePoint</name>
    <filename>classdimePoint.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimePoint</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a470b7c6dc7f1cb180922bd1e9eb914e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>ac6632727b0ffa5f4991b1bd45342a37d</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a475379f84b3e77ddfa69d40e34e9ec67</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a8cb5170d3e58dfd63e5f0bd779fe450d</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a1252a388d716a7a8da488c7f1726ff91</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a030fbb4899328687e2426a017bef60cc</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>afc46da580d5667e04d1f2b7d51697a6f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a78d0ff6105130664af5603015cdbdf1e</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimePoint.html</anchorfile>
      <anchor>a3c57698cc99166cd51f1debf99a936d2</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimePolyline</name>
    <filename>classdimePolyline.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimePolyline</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a169c14e83548a15cec6187ffcb306e46</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimePolyline</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a80c0a1feea73cc1135826f4661b20c4f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a42b4c7f5ab574f293ec2a6f718cac87f</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>adb49a30e826593fa61177bd04cd64119</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a71beeb74451a7b0c08454e7683d0662d</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a32460d31be925c9a30215593d972ef46</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a53aaba73db615b044b4193f0b2dbd66f</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getType</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>aa8eadd2a5c4f10a4cdb7d30a769ec51c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>af7cb5aab0453a8d224f171297da2e5f3</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCoordVertices</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>adbcc50f8aede30728756cad50ea388c8</anchor>
      <arglist>(dimeVertex **vertices, const int num, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIndexVertices</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a35dc0f8e2291d472a652345abb6c7f7b</anchor>
      <arglist>(dimeVertex **vertices, const int num, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setLayer</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a971c0bbf9515668b07d1ff3af8ba4ade</anchor>
      <arglist>(const dimeLayer *const layer)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSeqend</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a0c6d1578085019618d687406cc8072bb</anchor>
      <arglist>(const dimeEntity *ent)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSplineFrameControlPoints</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a8e07368a74de9dc7368224ed186260c4</anchor>
      <arglist>(dimeVertex **vertices, const int num, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a228eacf05a795c7a39434fe9d225095b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>abd59e88b44e94f10b6e006d611d184be</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a4680a9f9e1bbcc9daa0a7d133d7d2131</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>traverse</name>
      <anchorfile>classdimePolyline.html</anchorfile>
      <anchor>a272f40382a13b37730d1733411efd90b</anchor>
      <arglist>(const dimeState *const state, dimeCallback callback, void *userdata)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeRecord</name>
    <filename>classdimeRecord.html</filename>
    <base>dimeBase</base>
    <member kind="function">
      <type></type>
      <name>dimeRecord</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a2baf3af65e7bf7c01fedf6a9ff4e9dbb</anchor>
      <arglist>(const int group_code)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeRecord</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a06c982a909a4d114282550a17d707713</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a88e7dcb760db4d01eaf575ba0d92cef0</anchor>
      <arglist>(dimeMemHandler *const memhandler) const =0</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getGroupCode</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a1defaed06e09590dec8473260321e348</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>ab6f942bcd4bb1e484588df0d78e404e9</anchor>
      <arglist>(dimeParam &amp;param) const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEndOfFileRecord</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>ab67ef7f6045676f161187eb980a3881a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEndOfSectionRecord</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a8f72d67da947e1ca011494103a158b16</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>print</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a088f28ed8f11a31f2fc6bf352f14ea82</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a81dab7e43388e0e6f00d52f0a5672b42</anchor>
      <arglist>(dimeInput *const in)=0</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setGroupCode</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>aa5e1103335a293b5cfd4d5018c21fe99</anchor>
      <arglist>(const int group_code)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>aa1a9965079fcd2ccb43040f62b085b6a</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a15b2d484ce16f9caa3cc5cb60f8f09dc</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a8e61eb81306b3823e4dff26a1d46e772</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeRecord *</type>
      <name>createRecord</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>ac0730bcfee86cbc2a80fda3d63acb46e</anchor>
      <arglist>(const int group_code, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int</type>
      <name>getRecordType</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a8165f01643c475f3eaedeb543479d9f5</anchor>
      <arglist>(const int group_code)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeRecord *</type>
      <name>readRecord</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>adfed62fedff3e36e0ec3f677e09d0a52</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>readRecordData</name>
      <anchorfile>classdimeRecord.html</anchorfile>
      <anchor>a314f4eb7c8b992370d78078aa2f0cf14</anchor>
      <arglist>(dimeInput *const in, const int group_code, dimeParam &amp;param)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeRecordHolder</name>
    <filename>classdimeRecordHolder.html</filename>
    <base>dimeBase</base>
    <member kind="function">
      <type></type>
      <name>dimeRecordHolder</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a38ce4c66cb9e4990c63eda761b9b8f59</anchor>
      <arglist>(const int separator)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeRecordHolder</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a289cb834c4c8c9a6ba28cdd256d2828f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>ad504cbc990ee4cbea69483b5daa82981</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>dimeRecord *</type>
      <name>findRecord</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a7ec803ed2c97be0252a886cfdceff69f</anchor>
      <arglist>(const int groupcode, const int index=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumRecordsInRecordHolder</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>adaeac22dd6d64c9a2f7a8682c6708456</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>af169d5bff8a651d42b56ff1133ee4f5c</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>dimeRecord *</type>
      <name>getRecordInRecordHolder</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a60bd3fa02c4ebef8ca239689f80f2240</anchor>
      <arglist>(const int idx) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a8c145f4e746e24beb57db8e973a02bb6</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a1c352cacad3d4711dd522931908cee1e</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIndexedRecord</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>aa9f9e3657fef9223232a677664131d3a</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;value, const int index, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRecord</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a41059899b472a7eb689044851d251945</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;value, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRecords</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>aec7cbfb81036eef1c7b7862b2deb9229</anchor>
      <arglist>(const int *const groupcodes, const dimeParam *const params, const int numrecords, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a9367a4d51d30da5a0767cf07aae7fc94</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>copyRecords</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a13238655c7810a8cfaac52c957075555</anchor>
      <arglist>(dimeRecordHolder *const rh, dimeMemHandler *const memhandler) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a6aa688deeaf50dc8af631b1f5d8e381d</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>shouldWriteRecord</name>
      <anchorfile>classdimeRecordHolder.html</anchorfile>
      <anchor>a99682ef409b385d1a09ec4267b0a6fac</anchor>
      <arglist>(const int groupcode) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeSection</name>
    <filename>classdimeSection.html</filename>
    <base>dimeBase</base>
    <member kind="function">
      <type></type>
      <name>dimeSection</name>
      <anchorfile>classdimeSection.html</anchorfile>
      <anchor>abac07327f035dffe91f6b95d773ee1cb</anchor>
      <arglist>(dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeSection</name>
      <anchorfile>classdimeSection.html</anchorfile>
      <anchor>aa010d2c3930f7e37ef94857887c2c54e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeSection.html</anchorfile>
      <anchor>aab99b8204a76d5fd95524df17073cc1d</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeSection.html</anchorfile>
      <anchor>a0ea0546be1b9d1742ee911c7f7c7f252</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeSection.html</anchorfile>
      <anchor>afbc1f44e4fcc7c0fba86fb85ac14c5c1</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeSection *</type>
      <name>createSection</name>
      <anchorfile>classdimeSection.html</anchorfile>
      <anchor>a294c1bb069cabd514623540616070b3e</anchor>
      <arglist>(const char *const sectionname, dimeMemHandler *memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeSolid</name>
    <filename>classdimeSolid.html</filename>
    <base>dimeFaceEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeSolid</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a3a63b816224662c22b81c853160526e5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>aa7d706c71dfbc91f3bbb614e9f336994</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a596f8468998ef284866f074ff2a6551f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a06cec735d62cd714766bbe5da0219296</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getExtrusionDir</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a3b1cf3e06c56366a583f76ceb28d6210</anchor>
      <arglist>(dimeVec3f &amp;ed) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>adbb00746060c2ea035bc18f0eb1d5e26</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dxfdouble</type>
      <name>getThickness</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a708631c593bf661ef9da4a1e6594410e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a27dcb5bdeb0e11a67de9e52bf29e6749</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>ab889ea7f02edbf74d1cbdaaa13cade7f</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a9ddd9ab6b7612b8e4e993f5061767c12</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>swapQuadCoords</name>
      <anchorfile>classdimeSolid.html</anchorfile>
      <anchor>a7ccc9cdba1438760cfa85ae8623ff947</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeSpline</name>
    <filename>classdimeSpline.html</filename>
    <base>dimeEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeSpline</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>a3557d35287f2251833ba3239084c4614</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeSpline</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>a94f64f802ff3dd6ce179ba72c9adc150</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>af4d53b123b30740604b5da6d66a84a4a</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>a22a6b67d6c97ba9748d220c4510216e9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>a7c4bbaaaed2d9787f8f1932463dafe2a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>aacca6fb407856ed778784c085ba0a3b0</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasWeights</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>abc0b19dbf0c39eed42d49346cd2675f4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setControlPoints</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>ae600a31c039ca3dcddb1725ea4b075b9</anchor>
      <arglist>(const dimeVec3f *const pts, const int numpts, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWeight</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>ae7d5d183d6675072037fd1c9c129ee2e</anchor>
      <arglist>(const int idx, const dxfdouble w, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>ae66946c7eb017de9e97cb647554333cb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>ae404e662d174eea6a5b4f9bf8d661edd</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeSpline.html</anchorfile>
      <anchor>a99ff2b940cc57c0d2f868d41adb818fd</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeState</name>
    <filename>classdimeState.html</filename>
    <member kind="function">
      <type></type>
      <name>dimeState</name>
      <anchorfile>classdimeState.html</anchorfile>
      <anchor>a2446e9b6b0b500a071f9413b9d7ea3eb</anchor>
      <arglist>(const bool traversePolylineVertices, const bool explodeInserts)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>dimeState</name>
      <anchorfile>classdimeState.html</anchorfile>
      <anchor>a60dc191fca8dd92333bec00bb65672e2</anchor>
      <arglist>(const dimeState &amp;st)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeStringRecord</name>
    <filename>classdimeStringRecord.html</filename>
    <base>dimeRecord</base>
    <member kind="function">
      <type></type>
      <name>dimeStringRecord</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a4b7142bcdcda37edc1b257b6821d79f0</anchor>
      <arglist>(const int group_code=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeStringRecord</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a31b9f5eaa268a587e21a6aed27bb346f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeRecord *</type>
      <name>copy</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>abd89cc9aadc052f87978e8cf2cf3e24d</anchor>
      <arglist>(dimeMemHandler *const mh) const</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>getString</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a1faa1b8abba5adaa674a38e0df236cb9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getValue</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>ae32e772714a0717a83d91390595acf5e</anchor>
      <arglist>(dimeParam &amp;param) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEndOfFileRecord</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>ab55d8a6dd71190966abc9dcd213660a0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEndOfSectionRecord</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a925eefb896174ff09ae7448c14be51c2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a418af4e3148b5ebd2818b73d3a806cb7</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setString</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a85c69c516221b89c273623605b2bf8da</anchor>
      <arglist>(const char *const s, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setStringPointer</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a501a964f127c13d836c84f09c2c1741e</anchor>
      <arglist>(char *const s)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a49c67c10e65ca2d8067d11b61193bbc1</anchor>
      <arglist>(const dimeParam &amp;param, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a85383624568a61adbd8c9e4eef0c631c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeStringRecord.html</anchorfile>
      <anchor>a98d67555dfde5745ed97ab0ff5f0caf6</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeTable</name>
    <filename>classdimeTable.html</filename>
    <base>dimeBase</base>
    <member kind="function">
      <type></type>
      <name>dimeTable</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>ab8eda471bf4c16c80be1c705c02f2a78</anchor>
      <arglist>(dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeTable</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a3f42a489d6d873415492cfef113d0e2f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>countRecords</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>ad4c73384c11f857d33a4bef9ff51494f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumTableEntries</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a9a2fbcb362f89a03025e668d3c6d3f73</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumTableRecords</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a91694897f88560e63ad0dc46ab6f6bc9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>dimeTableEntry *</type>
      <name>getTableEntry</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a88efe3fc50834e0c620678d0155d8a96</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>dimeRecord *</type>
      <name>getTableRecord</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>ad9c90bff93dde3fe3454f5f2746d1d59</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertTableEntry</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>ab1007b366cf6f4bc705d05f47e3da230</anchor>
      <arglist>(dimeTableEntry *const tableEntry, const int idx=-1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertTableRecord</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a628a28c31a8dd7717247c85bddebb6a3</anchor>
      <arglist>(dimeRecord *const record, const int idx=-1)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a558c7ca8a4496cb470848755ff6715fb</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeTableEntry</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>ad87bd6cbc99d9446fbe324858a14e7ae</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeTableRecord</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a4b9007357ef54c818d372dff3519221d</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>typeId</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>ae97666c16c6e4ec1ef908e99ec8b5f4e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classdimeTable.html</anchorfile>
      <anchor>a480bce9f4e6e24a811d046da7864138b</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeTableEntry</name>
    <filename>classdimeTableEntry.html</filename>
    <base>dimeRecordHolder</base>
    <member kind="function">
      <type></type>
      <name>dimeTableEntry</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>a24969b3d9754998bd793a64110386197</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeTableEntry</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>af686feb8dacee2438f9cfb336ee4e20c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>ac6db8bfa6e45e6b0b3233a2e3ea4b8c5</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isOfType</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>afc90a7debf9b077b092a204793aaf462</anchor>
      <arglist>(const int thetypeid) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>a1f969e602d765638cd2624c80e7c3557</anchor>
      <arglist>(dimeInput *const in)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>ae14679c57607629413ae773de1f56f1c</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>a083d200f9ed289e74b3e114422460b4a</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static dimeTableEntry *</type>
      <name>createTableEntry</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>a2126722c709a8490423c998be0d43153</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>copyRecords</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>a0de5bc06313d6582abc803a3239538a0</anchor>
      <arglist>(dimeTableEntry *const table, dimeModel *const model) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeTableEntry.html</anchorfile>
      <anchor>a91cd1a40176f2345bee9af58305989f9</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeTablesSection</name>
    <filename>classdimeTablesSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeTablesSection</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a4af3c841c1d38137fc8241ff9e18b00d</anchor>
      <arglist>(dimeMemHandler *const memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeTablesSection</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a0cd5a0a2707cfb1b848716f16cbc8e7f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a903cfa1575fce51f7d3559c3ba5512a9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumTables</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>ac40c29fc2a85ab5523e823bbf1eac78c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>class dimeTable *</type>
      <name>getTable</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>aed9107cffb97d23b15981f8a9ec0cf1a</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insertTable</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a8d0fdeb4ebd323446096230e6b28a14f</anchor>
      <arglist>(dimeTable *const table, const int idx=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a055bcf8d9cde26a7f27434b8fafd3f73</anchor>
      <arglist>(dimeInput *const file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeTable</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a4b40d577e441996afbf681f0f3ecf91f</anchor>
      <arglist>(const int idx)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeTablesSection.html</anchorfile>
      <anchor>a6da1755f8a04ef34010f68c92a21e083</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeText</name>
    <filename>classdimeText.html</filename>
    <base>dimeExtrusionEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeText</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a2b7d6b7287d45c6d88439a382065d86d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a85a7ae3b7293a873696b46cec0dff4ed</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>ada239d57a143c0d9fdede8998891c9b6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GeometryType</type>
      <name>extractGeometry</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a2b8fa90496145d394214707bdf4c91a6</anchor>
      <arglist>(dimeArray&lt; dimeVec3f &gt; &amp;verts, dimeArray&lt; int &gt; &amp;indices, dimeVec3f &amp;extrusionDir, dxfdouble &amp;thickness)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a1207964f4b1817f98f38fc7b88c11f95</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>aa09b06321ed43a04a0803031e5e61478</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a2bcee9238ee7a76ff78ad66a4d932091</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a23ef787293800db40e0bd982a8b59d71</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeText.html</anchorfile>
      <anchor>a941b7c9d03a9212899d4344f8370d7d9</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeTrace</name>
    <filename>classdimeTrace.html</filename>
    <base>dimeFaceEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeTrace</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a8274be2b38985c5dd92added70e44694</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a09e371e146d8bbe96a9148b43e4600c6</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>aa1a3b6130179d09d032be4dc1b12c2a2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a9e6f2d2a53f85af0289a8d1ac3dc293f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>getExtrusionDir</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>af0a8449738ae4679f6ad2a66ad344991</anchor>
      <arglist>(dimeVec3f &amp;ed) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a019061079c7db45751d5124bd41dd70e</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dxfdouble</type>
      <name>getThickness</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a8551a293ffb994e099a5386976eac4f7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a303d0a0faa166d6a3d068319e3201d19</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a5f7fe2fa87c427b3142b5c2d79e1582b</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a36f675e1f1000b530d6fbbe72efb127c</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>swapQuadCoords</name>
      <anchorfile>classdimeTrace.html</anchorfile>
      <anchor>a648b344de3cea3a27c9deb30e6ffa683</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeUCSTable</name>
    <filename>classdimeUCSTable.html</filename>
    <base>dimeTableEntry</base>
    <member kind="function">
      <type></type>
      <name>dimeUCSTable</name>
      <anchorfile>classdimeUCSTable.html</anchorfile>
      <anchor>a00b0fca1de7adc8ccd0f6bfe6b2a6e22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeUCSTable.html</anchorfile>
      <anchor>ad3143a5ecbbe63585b55fbfea475b0f5</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeUCSTable.html</anchorfile>
      <anchor>a8822fdc9a39d3fc3839ac9dbbd236240</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeUCSTable.html</anchorfile>
      <anchor>ad6ab7915677e5f0c03cf2e7f2b5c3bfc</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeUCSTable.html</anchorfile>
      <anchor>a492ef89debf211eb4a1280d3e50467e6</anchor>
      <arglist>(const int groupcodes, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeUnknownClass</name>
    <filename>classdimeUnknownClass.html</filename>
    <base>dimeClass</base>
    <member kind="function">
      <type></type>
      <name>dimeUnknownClass</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>ab8f20f4b73cbf43197339d3feb8329cb</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeUnknownClass</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>a5b07307d76cf0f71aa90cc46f8078a42</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeClass *</type>
      <name>copy</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>a95e6d5e680912ee413c287514292b3cc</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>a01394ab6b1251642ea1af9ec2fa43a26</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getDxfClassName</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>aebf19ed180d1c8ac945c97ae157e06d3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>a9a8cff2e54e8e49901a9faefa682599d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeUnknownClass.html</anchorfile>
      <anchor>af1020aaab599bed770d3218d2efae920</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeUnknownEntity</name>
    <filename>classdimeUnknownEntity.html</filename>
    <base>dimeEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeUnknownEntity</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>a4f278a152815c717bbf12e36613affc4</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeUnknownEntity</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>a2fd2ebac1d1cfdccd490af2524beac8f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>addd3dfc23d46d3fe8810c8a74437ef0b</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>acc357ce161889b99be03aebcacdf8243</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>a94b7731f0f6f16945c90cc99e91e10fb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>abbdfe45b705a0699bde291c9e6c2f3fb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeUnknownEntity.html</anchorfile>
      <anchor>ac6c9d169ff62b9e2740cf12eec4873b3</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeUnknownObject</name>
    <filename>classdimeUnknownObject.html</filename>
    <base>dimeObject</base>
    <member kind="function">
      <type></type>
      <name>dimeUnknownObject</name>
      <anchorfile>classdimeUnknownObject.html</anchorfile>
      <anchor>a9e4efd42b77a5a3bf4af04b5193ee573</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeUnknownObject</name>
      <anchorfile>classdimeUnknownObject.html</anchorfile>
      <anchor>a523a5717905a6c6aca9c41705a674f44</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeUnknownObject.html</anchorfile>
      <anchor>adde9bbecb8bf472366a9b6debc474f8a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeUnknownObject.html</anchorfile>
      <anchor>a14b43479ec96890d507a73d2fbbb4be0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeUnknownObject.html</anchorfile>
      <anchor>af2ac7955aecc73b86226dfc76aef349a</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeUnknownSection</name>
    <filename>classdimeUnknownSection.html</filename>
    <base>dimeSection</base>
    <member kind="function">
      <type></type>
      <name>dimeUnknownSection</name>
      <anchorfile>classdimeUnknownSection.html</anchorfile>
      <anchor>a04109a05a0760fb8d6cb374d28b45667</anchor>
      <arglist>(const char *const sectionname, dimeMemHandler *memhandler=NULL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeUnknownSection</name>
      <anchorfile>classdimeUnknownSection.html</anchorfile>
      <anchor>a326a55b334deba40389253630afc3b34</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeUnknownSection.html</anchorfile>
      <anchor>a43d2b4bcb7853a4b77a732bbb42f0916</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeUnknownSection.html</anchorfile>
      <anchor>ad2755a4c9dd3ba80d23635a570a73744</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeUnknownTable</name>
    <filename>classdimeUnknownTable.html</filename>
    <base>dimeTableEntry</base>
    <member kind="function">
      <type></type>
      <name>dimeUnknownTable</name>
      <anchorfile>classdimeUnknownTable.html</anchorfile>
      <anchor>ab4cdddce9dff5f71458e1dfd2a3d12fe</anchor>
      <arglist>(const char *const name, dimeMemHandler *const memhandler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~dimeUnknownTable</name>
      <anchorfile>classdimeUnknownTable.html</anchorfile>
      <anchor>a632341614c20301091cd209678d22dd1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeUnknownTable.html</anchorfile>
      <anchor>a5f1cf86fb4da0815f57fa393d4b8ba37</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeUnknownTable.html</anchorfile>
      <anchor>a28a7435c8ce842d2f19d34c5ba0c6889</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeUnknownTable.html</anchorfile>
      <anchor>a46a34ae395fd5759fae39f1b75919e09</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dimeVec2f</name>
    <filename>classdimeVec2f.html</filename>
  </compound>
  <compound kind="class">
    <name>dimeVec3f</name>
    <filename>classdimeVec3f.html</filename>
  </compound>
  <compound kind="class">
    <name>dimeVertex</name>
    <filename>classdimeVertex.html</filename>
    <base>dimeEntity</base>
    <member kind="function">
      <type></type>
      <name>dimeVertex</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>a7c77814afd2419cff6681221edba217f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual dimeEntity *</type>
      <name>copy</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>abdf465612c88895efcbf743f9911352c</anchor>
      <arglist>(dimeModel *const model) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>countRecords</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>a256ca41a8c67d696d01d73ff3573f54e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>getEntityName</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>a6be4cf60db8879e065d8a2778058baa8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getIndex</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>a85ba66b186dd568288742b924311ef1b</anchor>
      <arglist>(const int idx) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getRecord</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>addead7cfdcacfeae5e5269038f56c635</anchor>
      <arglist>(const int groupcode, dimeParam &amp;param, const int index=0) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>numIndices</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>a867bd8f709229202ebc44b424b44fcaa</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>typeId</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>a29250a5b00f3338138056cc27e5d4bd4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>aab89e4264701bdae94defc1c49ab0b9b</anchor>
      <arglist>(dimeOutput *const out)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>handleRecord</name>
      <anchorfile>classdimeVertex.html</anchorfile>
      <anchor>ac1c75f974fa1090366f0a2f490f05258</anchor>
      <arglist>(const int groupcode, const dimeParam &amp;param, dimeMemHandler *const memhandler)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dxfConverter</name>
    <filename>classdxfConverter.html</filename>
    <member kind="function">
      <type></type>
      <name>dxfConverter</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>aa87dbfb5a9c57cbf923eeab4da19b5d1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dxfConverter</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a346139596d536757f95dbb720ad5b105</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doConvert</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>ae3709f172981731d3e53332cd457c4d9</anchor>
      <arglist>(dimeModel &amp;model)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>findHeaderVariables</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>ae60f7b968aa9adbe0c1edc1e3ea5eb39</anchor>
      <arglist>(dimeModel &amp;model)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getColorIndex</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>add1546c5596d855921a239a5232c10fc</anchor>
      <arglist>(const dimeEntity *entity)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getCurrentInsertColorIndex</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>afd96281dc97003ac1a1136db97598f57</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getFillmode</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>aac5143d5ff2035811990e891d6c4ebe3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getLayercol</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a480917ec0c234b65ff6a7e9b65d5f69b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>dxfLayerData **</type>
      <name>getLayerData</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a6dd401e527903965a435d609e4b3bf8d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>dxfLayerData *</type>
      <name>getLayerData</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a748ce81fb97745cf2d67312744ca0d2c</anchor>
      <arglist>(const dimeEntity *entity)</arglist>
    </member>
    <member kind="function">
      <type>dxfLayerData *</type>
      <name>getLayerData</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>aceb1c92671595baf42e4dd0096131411</anchor>
      <arglist>(const int colidx)</arglist>
    </member>
    <member kind="function">
      <type>dxfdouble</type>
      <name>getMaxerr</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a8712e23435c6575f08d34594e2dfb7db</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumSub</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a311bfaf323eea4b7e465073b87293e87</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFillmode</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a37af83f4b0fadf2619679a6ca2fb401f</anchor>
      <arglist>(const bool fill)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLayercol</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a132c6ce0b23c420a0598e4ebac97a32d</anchor>
      <arglist>(const bool v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMaxerr</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a4d4eef552937f81f92144470348b3809</anchor>
      <arglist>(const dxfdouble maxerr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNumSub</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a70dda51fd8f98e3a5f1d35a2ca4a748a</anchor>
      <arglist>(const int num)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeVrml</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a0bc052302be33c44613832f3a2eb5e8f</anchor>
      <arglist>(const char *filename, const bool vrml1=false, const bool only2d=false)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeVrml</name>
      <anchorfile>classdxfConverter.html</anchorfile>
      <anchor>a78a3b35c67aaea801d24185a767f04d5</anchor>
      <arglist>(FILE *out, const bool vrml1=false, const bool only2d=false)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dxfLayerData</name>
    <filename>classdxfLayerData.html</filename>
    <member kind="function">
      <type></type>
      <name>dxfLayerData</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>a12d7972794f431491f227dd66617bcf3</anchor>
      <arglist>(const int colidx)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~dxfLayerData</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>a4116ec5b44433cfd9a5a00dbc1374b0f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addLine</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>a0ee3b4c5d734c02b23f51498bc7d55b5</anchor>
      <arglist>(const dimeVec3f &amp;v0, const dimeVec3f &amp;v1, const dimeMatrix *const matrix=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addPoint</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>a002a2af0032af251ef9b94d00de582ee</anchor>
      <arglist>(const dimeVec3f &amp;v, const dimeMatrix *const matrix=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addQuad</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>acd87ad59407276c5b27ade2e3844e16e</anchor>
      <arglist>(const dimeVec3f &amp;v0, const dimeVec3f &amp;v1, const dimeVec3f &amp;v2, const dimeVec3f &amp;v3, const dimeMatrix *const matrix=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addTriangle</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>ad370fcba0e12d4cec548860a35b66834</anchor>
      <arglist>(const dimeVec3f &amp;v0, const dimeVec3f &amp;v1, const dimeVec3f &amp;v2, const dimeMatrix *const matrix=NULL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFillmode</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>add9e99431e3395c8218eb966b62c0436</anchor>
      <arglist>(const bool fillmode)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>writeWrl</name>
      <anchorfile>classdxfLayerData.html</anchorfile>
      <anchor>a3f12b5da16b8b05fd318e6c72ad735fa</anchor>
      <arglist>(FILE *fp, int indent, const bool vrml1, const bool only2d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>dxfLineSegment</name>
    <filename>classdxfLineSegment.html</filename>
    <member kind="function">
      <type>void</type>
      <name>convert</name>
      <anchorfile>classdxfLineSegment.html</anchorfile>
      <anchor>a11dfeec7a5df4ba7c72e701f12800f1a</anchor>
      <arglist>(dxfLineSegment *prev, dxfLineSegment *next, dxfLayerData *data, dimeMatrix *matrix)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classdxfLineSegment.html</anchorfile>
      <anchor>aa8d0211d3be4bd07bf42dd62bd10c860</anchor>
      <arglist>(const dimeVec3f &amp;p0, const dimeVec3f &amp;p1, const dxfdouble startWidth, const dxfdouble endwidth, const dxfdouble thickness)</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>dime</title>
    <filename>index.html</filename>
  </compound>
</tagfile>
