//
// Created by hal9000 on 4/3/23.
//

#ifndef UNTITLED_ISOPARAMETRICNODEGRAPH_H
#define UNTITLED_ISOPARAMETRICNODEGRAPH_H

#include "Node.h"
#include "../../LinearAlgebra/Operations/VectorOperations.h"

using namespace Discretization;

namespace Discretization {

    class IsoParametricNodeGraph {
        
    public:
        
        IsoParametricNodeGraph(Node* node, unsigned graphDepth, map<vector<double>, Node*> *nodeMap,
                               map<Direction, unsigned>& nodesPerDirection, bool includeDiagonalNeighbours = true);

        // Returns a map ptr of the input node neighbours graph
        // Key : Position Enum representing the position of the neighbour node relative to the input node.
        // Value : Vector Node ptr of the neighbour nodes at all the input depth levels. (length = depth)
        // Warning : Always deallocate the returned pointer.
        map<Position, vector<Node*>>* getNodeGraph() ;
        
        map<Position, vector<Node*>>* getNodeGraph(const map<Position,short unsigned>& customDepth) ;

        // Returns a map ptr graph with all the Degrees Of Freedom of the input node neighbours.
        // Key : Position Enum representing the position of the neighbour node relative to the input node.
        // Value : Vector of DegreeOfFreedom Pointers vector pointer at all the input depth levels.
        // Warning : Always deallocate the returned pointer.
        map<Position, vector<vector<DegreeOfFreedom*>*>>* getAllDOFGraph() const ;

        // Map ptr graph with a specific Degree Of Freedom of the input node neighbours (free and constrained).
        // Key : Position Enum representing the position of the neighbour node relative to the input node.
        // Value : Vector of DegreeOfFreedom Pointers vector pointer at all the input depth levels.
        // Warning : Always deallocate the returned pointer.
        map<Position, vector<DegreeOfFreedom*>>* getSpecificDOFGraph(DOFType dofType) const ;

        // Map ptr graph with a specific Degree Of Freedom of the input node neighbours (free or constrained).
        // Key : Position Enum representing the position of the neighbour node relative to the input node.
        // Value : Vector of DegreeOfFreedom Pointers vector pointer at all the input depth levels.
        // Warning : Always deallocate the returned pointer.
        map<Position, vector<DegreeOfFreedom*>>* getSpecificDOFGraph(DOFType dofType, ConstraintType constraint) const ;
        
        // Returns a map ptr graph with all the Nodes that belong at the same parametric coordinate line as the input node.
        // Key : Direction Enum representing the direction of the parametric coordinate line.
        // Value : Vector of Node ptr at all depth nodes. They are ordered with increasing parametric coordinate value.
        //         The input node is included in the vector.
        map<Direction, vector<Node*>>* getColinearNodes() const;
        
        vector<Node*> getColinearNodes(Direction direction) const;

        map<Direction, vector<double>> getColinearNodalCoordinate(CoordinateType coordinateType) const;
        
        vector<double> getColinearNodalCoordinate(CoordinateType coordinateType, Direction direction) const;
        
        map<Direction, vector<DegreeOfFreedom*>> getColinearDOF(DOFType dofType) const;

        vector<double> getColinearDOF(DOFType dofType, Direction direction) const;
        
        


        map<Position, vector<Node*>>* nodeGraph;
                
    private:

        Node* _node;
        
        unsigned int _graphDepth;
        
        map<vector<double>, Node*>* _nodeMap;
        
        map<Direction, unsigned> _nodesPerDirection;
                
        void _findINeighborhoodRecursively(bool includeDiagonalNeighbours);
        
        void _findIDepthNeighborhood(unsigned int depth, vector<double>& nodeCoords);
        
        void _findIDepthNeighborhoodOnlyDiagonals(unsigned int depth, vector<double>& nodeCoords);

        void _addNeighbourNodeIfParametricCoordsExist(Position position, vector<double>& parametricCoords,  unsigned depthSize);
    };

} // Node

#endif //UNTITLED_ISOPARAMETRICNODEGRAPH_H
