//
// Created by hal9000 on 12/6/22.
//

#include "SecondOrderLinearPDEProperties.h"
#include "../Primitives/Matrix.h"
#include "../Discretization/Node.h"
#include "iostream"
#include "vector"
#include "map"
namespace PartialDifferentialEquations {
    
    SecondOrderLinearPDEProperties::SecondOrderLinearPDEProperties(Matrix<double> *secondOrderCoefficients,
                                                                   vector<double> *firstOrderCoefficients,
                                                                   double *zerothOrderCoefficient,
                                                                   double *sourceTerm) {
        _type = PropertiesDistributionType::Isotropic;
        _secondDerivativeIsotropicProperties = secondOrderCoefficients;
        _firstDerivativeIsotropicProperties = firstOrderCoefficients;
        _zeroDerivativeIsotropicProperties = zerothOrderCoefficient;
        _sourceProperties = sourceTerm;
        
        _secondDerivativeFieldAnisotropicProperties = nullptr;
        _firstDerivativeFieldAnisotropicProperties = nullptr;
        _zeroDerivativeFieldAnisotropicProperties = nullptr;
        _secondDerivativeLocallyAnisotropicProperties = nullptr;
        _firstDerivativeLocallyAnisotropicProperties = nullptr;
        _zeroDerivativeLocallyAnisotropicProperties = nullptr;
        _sourceLocallyAnisotropicProperties = nullptr;
    }
    
    SecondOrderLinearPDEProperties::SecondOrderLinearPDEProperties(Matrix<Matrix<double>> *secondOrderCoefficients,
                                                                   vector<vector<double>> *firstOrderCoefficients,
                                                                   double *zerothOrderCoefficient,
                                                                   double *sourceTerm) {
        _type = PropertiesDistributionType::FieldAnisotropic;
        _secondDerivativeFieldAnisotropicProperties = secondOrderCoefficients;
        _firstDerivativeFieldAnisotropicProperties = firstOrderCoefficients;
        _zeroDerivativeFieldAnisotropicProperties = zerothOrderCoefficient;
        _sourceProperties = sourceTerm;
        
        _secondDerivativeIsotropicProperties = nullptr;
        _firstDerivativeIsotropicProperties = nullptr;
        _zeroDerivativeIsotropicProperties = nullptr;
        _secondDerivativeLocallyAnisotropicProperties = nullptr;
        _firstDerivativeLocallyAnisotropicProperties = nullptr;
        _zeroDerivativeLocallyAnisotropicProperties = nullptr;
        _sourceLocallyAnisotropicProperties = nullptr;
        
    }
    
    SecondOrderLinearPDEProperties::SecondOrderLinearPDEProperties(map<int*, Matrix<Matrix<double>>> *secondOrderCoefficients,
                                                                   map<int*, vector<vector<double>>> *firstOrderCoefficients,
                                                                   map<int*, double> *zerothOrderCoefficients,
                                                                   map<int*, double> *sourceTerms) {
        _type = PropertiesDistributionType::LocallyAnisotropic;
        _secondDerivativeLocallyAnisotropicProperties = secondOrderCoefficients;
        _firstDerivativeLocallyAnisotropicProperties = firstOrderCoefficients;
        _zeroDerivativeLocallyAnisotropicProperties = zerothOrderCoefficients;
        _sourceLocallyAnisotropicProperties = sourceTerms;
        
        _secondDerivativeIsotropicProperties = nullptr;
        _firstDerivativeIsotropicProperties = nullptr;
        _zeroDerivativeIsotropicProperties = nullptr;
        _secondDerivativeFieldAnisotropicProperties = nullptr;
        _firstDerivativeFieldAnisotropicProperties = nullptr;
        _zeroDerivativeFieldAnisotropicProperties = nullptr;
        _sourceProperties = nullptr;
    }
    
    PropertiesDistributionType SecondOrderLinearPDEProperties::Type() {
        return _type;
    }
    
    template<class T>
    T *SecondOrderLinearPDEProperties::SecondOrderCoefficients() {
        switch (_type) {
            case PropertiesDistributionType::Isotropic:
                return _secondDerivativeIsotropicProperties;
            case PropertiesDistributionType::FieldAnisotropic:
                return _secondDerivativeFieldAnisotropicProperties;
            case PropertiesDistributionType::LocallyAnisotropic:
                return _secondDerivativeLocallyAnisotropicProperties;
        }
    }
    
    template<class T>
    T *SecondOrderLinearPDEProperties::FirstOrderCoefficients() {
        switch (_type) {
            case PropertiesDistributionType::Isotropic:
                return _firstDerivativeIsotropicProperties;
            case PropertiesDistributionType::FieldAnisotropic:
                return _firstDerivativeFieldAnisotropicProperties;
            case PropertiesDistributionType::LocallyAnisotropic:
                return _firstDerivativeLocallyAnisotropicProperties;
        }
    }
    
    template<class T>
    T *SecondOrderLinearPDEProperties::ZerothOrderCoefficient() {
        switch (_type) {
            case PropertiesDistributionType::Isotropic:
                return _zeroDerivativeIsotropicProperties;
            case PropertiesDistributionType::FieldAnisotropic:
                return _zeroDerivativeFieldAnisotropicProperties;
            case PropertiesDistributionType::LocallyAnisotropic:
                return _zeroDerivativeLocallyAnisotropicProperties;
        }
    }
    
    template<class T>
    T *SecondOrderLinearPDEProperties::SourceTerm() {
        switch (_type) {
            case PropertiesDistributionType::LocallyAnisotropic:
                return _sourceLocallyAnisotropicProperties;
            default:
                return _sourceProperties;
        }
    }
       
} // PartialDifferentialEquations