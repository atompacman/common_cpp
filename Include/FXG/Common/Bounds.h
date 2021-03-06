#ifndef FXGUILD_COMMON_BOUNDS
#define FXGUILD_COMMON_BOUNDS

/*================================================================================================\\
| Bounds, Limits or Interval between two quantities of the same type
|--------------------------------------------------------------------------------------------------|
| Type T should have a natural order and implement basic arithmetic and comparison operators.
\=================================================================================================*/

#include <algorithm>

namespace FXG { namespace Common {

template <typename T>
class Bounds
{
public:

    T Min;
    T Max;

    explicit Bounds<T>() :
        Min(),
        Max()
    {}

    explicit Bounds<T>(T const & i_Min, T const & i_Max) :
        Min(i_Min),
        Max(i_Max)
    {}

    explicit Bounds<T>(Bounds<T> const & i_Other) :
        Min(i_Other.Min),
        Max(i_Other.Max)
    {}

    Bounds<T> & operator = (Bounds<T> const & i_Other)
    {
        Min = i_Other.Min;
        Max = i_Other.Max;
        return *this;
    }

    bool contains(T const & i_Elem) const
    {
        return i_Elem >= Min && i_Elem <= Max;
    }

    T size() const
    {
        return Max - Min;
    }

    T center() const
    {
        return (Max - Min) / 2;
    }

    T clamp(T const & i_Elem) const
    {
        return std::min(std::max(i_Elem, Min), Max);
    }
};

// Synonyms
template <typename T> using Limits   = Bounds<T>;
template <typename T> using Interval = Bounds<T>;

}}

#endif // FXGUILD_COMMON_BOUNDS