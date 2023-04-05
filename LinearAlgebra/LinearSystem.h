//
// Created by hal9000 on 3/28/23.
//

#ifndef UNTITLED_LINEARSYSTEM_H
#define UNTITLED_LINEARSYSTEM_H

#include "../Analysis/AnalysisDOFs/AnalysisDegreesOfFreedom.h"
#include "Array.h"
#include "../Discretization/Node/IsoParametricNeighbourFinder.h"

using namespace NumericalAnalysis;

namespace LinearAlgebra {

    class LinearSystem {
        public:
            explicit LinearSystem(AnalysisDegreesOfFreedom* analysisDegreesOfFreedom, Mesh* mesh);
            
            ~LinearSystem();
            
            Array<double>* matrix;
            
            vector<double>* RHS;
            
            unsigned* numberOfFreeDOFs;
            
            unsigned* numberOfFixedDOFs;
            
            unsigned* numberOfDOFs;
            
            void createLinearSystem();
            
            void updateRHS();
    private:
        
        Mesh* _mesh;

        IsoParametricNeighbourFinder* _isoParametricNeighbourFinder;
        
        AnalysisDegreesOfFreedom* _analysisDegreesOfFreedom;
        
        Array<double>* _freeDOFMatrix;

        // Fixed DOF x Total DOF
        Array<double>* _fixedDOFMatrix;

        void _createMatrix();
        void _createFixedDOFSubMatrix();
        void _createFreeDOFSubMatrix();

        
        void _createRHS();
    };

} // LinearAlgebra

#endif //UNTITLED_LINEARSYSTEM_H

