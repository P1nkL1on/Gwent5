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

template <typename Ts>
Ts filtered(const std::vector<std::function<bool (typename Ts::const_iterator::value_type)>> &filters, const Ts &ts)
{
    Ts dst;
    for (size_t i = 0; i < ts.size(); ++i) {
        bool filteredOut = false;
        for (const auto &filter : filters)
            if (!filter(ts[i])) {
                filteredOut = true;
                break;
            }
        if (filteredOut)
            continue;
        dst.push_back(ts[i]);
    }
    return dst;
}

template <typename Ts>
Ts united(const std::vector<Ts> &vectors)
{
    size_t total = 0;
    for (const Ts &ts : vectors)
        total += ts.size();
    Ts dst(total, nullptr);
    for (size_t iDst = 0, i = 0, j = 0;;) {
        if (vectors[j].size() > 0) {
            dst[iDst] = vectors[j][i];
            ++iDst;
        }
        ++i;
        if (i >= vectors[j].size()) {
            i = 0;
            ++j;
        }
        if (j >= vectors.size())
            break;
    }
    return dst;
}


#endif // ITERATOR_H
