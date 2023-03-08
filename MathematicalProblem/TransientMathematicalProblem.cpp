//
// Created by hal9000 on 12/17/22.
//

#include "TransientMathematicalProblem.h"

namespace MathematicalProblem {
    
    
    TransientMathematicalProblem :: TransientMathematicalProblem(
            PartialDifferentialEquation *pde,
            map<Position,list<BoundaryConditions::BoundaryCondition*>> *bcs,map<int*,double>* domainIC,
            struct Field_DOFType *degreesOfFreedom) :
                                pde(pde), boundaryConditions(bcs),
                                initialCondition(nullptr),
                                domainInitialConditions(domainIC),
                                degreesOfFreedom(degreesOfFreedom) { }


}// MathematicalProblem