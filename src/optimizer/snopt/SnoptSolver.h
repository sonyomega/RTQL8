/*
 * RTQL8, Copyright (c) 2011, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Sehoon Ha <sehoon.ha@gmail.com>
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

#ifndef OPTIMIZER_SNOPT_SNOPT_H
#define OPTIMIZER_SNOPT_SNOPT_H

#include <vector>
#include <Eigen/Dense>
#include "SnoptInterface.h"
#include "optimizer/Solver.h"

namespace optimizer {
    class Problem;
    class ConstraintBox;
    class ObjectiveBox;
    class Var;
    
    namespace snopt {

        class SnoptSolver : public Solver {
        public:
            SnoptSolver(Problem *problem);
            virtual ~SnoptSolver();

            virtual bool solve();

            virtual void resetSolver();
            static int iterUpdate(long mask, int compute_gradients, double *coefs, void *update_data);
        private:
            SnoptInterface *mSnopt;
            /* std::vector<Dofs> mVariables; */
            /* ConstrBox* mConstrBox; */
            /* ObjBox* mObjBox; */

            ConstraintBox* conBox();
            ObjectiveBox* objBox();

            bool mNoDisplay;
            int mSolverIter;

            int mTotalDofs;
            int mOptCount;
            bool mPrint;
            int mUnit;


        };

        
    } // namespace snopt
} // namespace optimizer

#endif // #ifndef OPTIMIZER_SNOPT_SNOPT_H

