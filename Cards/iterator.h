#ifndef ITERATOR_H
#define ITERATOR_H

#include <functional>
#include <vector>
#include <iostream>


template <typename ItBase>
struct ItFilter;

template <typename Ts>
Ts filtered(const std::vector<typename ItFilter<typename Ts::const_iterator>::Filter> &filters, const Ts &ts);

template <typename Ts>
Ts united(const std::vector<const Ts &> &tss);









/// imlementation

template <typename ItBase>
struct ItFilter : ItBase
{
    using Filter = std::function<bool (typename ItBase::value_type)>;

    ItFilter() = default;
    ItFilter(const std::vector<Filter> &filters, ItBase base, ItBase end) :
        ItBase(base),
        _end(end),
        _filters(filters)
    {
        while (shouldAdvance()) {
            ++*this;
        }
    }
    void operator++()
    {
        do {
            ItBase::operator++();
        } while (shouldAdvance());
    }
    bool shouldAdvance() const
    {
        if (*this == _end)
            return false;

        for (const Filter &filter : _filters)
            if (!filter(**this))
                return true;

        return false;
    }
private:
    ItBase _end;
    std::vector<Filter> _filters;
};

template <typename ItBase>
ItFilter<ItBase> itFilter(
        typename ItFilter<ItBase>::Filter filter,
        ItBase base,
        ItBase end = {})
{
    return {filter, base, end};
}

template <typename Ts>
Ts filtered(const std::vector<typename ItFilter<typename Ts::const_iterator>::Filter> &filters, const Ts &ts)
{
    using Iter = ItFilter<typename Ts::const_iterator>;
    struct Wrapper : Ts
    {
        Wrapper(Iter b, Iter e) : Ts(b, e), _begin(b), _end(e) {}
        Iter _begin;
        Iter _end;
        Iter begin() { return _begin; }
        Iter end() { return _end; }
    };
    const Iter begin(filters, ts.begin(), ts.end());
    const Iter end({}, ts.end(), ts.end());
    return Wrapper(begin, end);
}

template <typename Ts>
Ts united(const std::vector<Ts> &vectors)
{
    size_t total = 0;
    for (const Ts &ts : vectors)
        total += ts.size();
    Ts dst(total);
    for (size_t i = 0, vi = 0, vj = 0;;) {
        if (vectors[vj].size() > 0) {
            dst[i] = vectors[vj][vi];
            ++vi;
        }
        if (vi >= vectors[vj].size()) {
            vi = 0;
            ++vj;
        }
        ++i;
        if (vj >= vectors.size())
            break;
    }
    return dst;
}


#endif // ITERATOR_H
