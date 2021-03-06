/*
 * RTQL8, Copyright (c) 2011, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Sumit Jain <sumitj83@gmail.com>, Sehoon Ha <sehoon.ha@gmail.com>
 *
 * Geoorgia Tech Graphics Lab
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KINEMATICS_TRFM_ROTATE_EULER_H
#define KINEMATICS_TRFM_ROTATE_EULER_H

#include "Transformation.h"
#include <cassert>

namespace kinematics {
    // rotate about x axis
    class TrfmRotateEulerX: public Transformation {
    public:
        TrfmRotateEulerX(Dof *x, const char *_name=NULL);

        Eigen::Matrix4d getInvTransform();
	
		void applyGLTransform(renderer::RenderInterface* _ri) const;
        void computeTransform();
        Eigen::Matrix4d getDeriv(const Dof *q);
        Eigen::Matrix4d getSecondDeriv(const Dof *q1, const Dof *q2);
    };

    // rotate about y axis
    class TrfmRotateEulerY: public Transformation {
    public:
        TrfmRotateEulerY(Dof *y, const char *_name=NULL);

        Eigen::Matrix4d getInvTransform();
	
        void applyGLTransform(renderer::RenderInterface* _ri) const;
        void computeTransform();
        Eigen::Matrix4d getDeriv(const Dof *q);
        Eigen::Matrix4d getSecondDeriv(const Dof *q1, const Dof *q2);
    };


// rotate about z axis
    class TrfmRotateEulerZ: public Transformation {
    public:
        TrfmRotateEulerZ(Dof *z, const char *_name=NULL);

        Eigen::Matrix4d getInvTransform();
	
        void applyGLTransform(renderer::RenderInterface* _ri) const;
        void computeTransform();
        Eigen::Matrix4d getDeriv(const Dof *q);
        Eigen::Matrix4d getSecondDeriv(const Dof *q1, const Dof *q2);
    };
} // namespace kinematics

#endif // #ifndef KINEMATICS_ROTATE_EULER_H

