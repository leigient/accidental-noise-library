#ifndef IMPLICITMATH_H
#define IMPLICITMATH_H

#include "implicitmodulebase.h"

#include <cmath>

namespace anl
{
    enum EUnaryMathOperation
    {
        ACOS,
        ASIN,
        ATAN,
        COS,
        SIN,
        TAN,
        ABS,
        FLOOR,
        CEIL,
        EXP,
        LOG10,
        LOG2,
        LOGN,
        ONEMINUS,
        SQRT,
        INTEGER,
        FRACTIONAL,
		EASECUBIC,
		EASEQUINTIC,
    };

    enum EBinaryMathOperation
    {
        POW=EASEQUINTIC+1,
        FMOD,
        BIAS,
        GAIN,
        PMINUS,
        SUM,
        MULTIPLY,
        DIVIDE,
        SUBTRACT,
        MAXIMUM,
        MINIMUM
    };

    class CImplicitMath : public CImplicitModuleBase
    {
        public:
        CImplicitMath();
        CImplicitMath(unsigned int op, double source=1, double p=1);
        CImplicitMath(unsigned int op, CImplicitModuleBase * source=0, double p=1);
        CImplicitMath(unsigned int op, double source=0, CImplicitModuleBase * p=0);
        CImplicitMath(unsigned int op, CImplicitModuleBase * source=0, CImplicitModuleBase * p=0);
        ~CImplicitMath();

        void setSource(double v);
        void setSource(CImplicitModuleBase * b);
        void setParameter(double v);
        void setParameter(CImplicitModuleBase * b);
        void setOperation(unsigned int op);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        unsigned int m_op;
        CScalarParameter m_source;
        CScalarParameter m_parameter;

        double applyOp(double v, double p);
    };
};

#endif
