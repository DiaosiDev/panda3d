// Filename: accumulatedAttribs.h
// Created by:  drose (30Jan03)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#ifndef ACCUMULATEDATTRIBS_H
#define ACCUMULATEDATTRIBS_H

#include "pandabase.h"
#include "transformState.h"
#include "renderAttrib.h"
#include "renderState.h"
#include "pointerTo.h"

class PandaNode;

////////////////////////////////////////////////////////////////////
//       Class : AccumulatedAttribs
// Description : This class is used by the SceneGraphReducer to
//               maintain and accumulate the set of attributes we have
//               encountered on each node that might eventually be
//               applied to the vertices at the leaves.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA_PGRAPH AccumulatedAttribs {
public:
  AccumulatedAttribs();
  AccumulatedAttribs(const AccumulatedAttribs &copy);
  void operator = (const AccumulatedAttribs &copy);
  
  void write(ostream &out, int attrib_types, int indent_level) const;
  
  void collect(PandaNode *node, int attrib_types);
  CPT(RenderState) collect(const RenderState *state, int attrib_types);
  void apply_to_node(PandaNode *node, int attrib_types);

  CPT(TransformState) _transform;
  CPT(RenderAttrib) _color;
  int _color_override;
  CPT(RenderAttrib) _color_scale;
  int _color_scale_override;
  CPT(RenderAttrib) _tex_matrix;
  int _tex_matrix_override;
  CPT(RenderAttrib) _texture;
  int _texture_override;
  CPT(RenderAttrib) _clip_plane;
  int _clip_plane_override;
  CPT(RenderAttrib) _cull_face;
  int _cull_face_override;
  CPT(RenderState) _other;
};

#include "accumulatedAttribs.I"

#endif


