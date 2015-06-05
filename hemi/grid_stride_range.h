/////////////////////////////////////////////////////////////////
// Some utility code to define grid_stride_range
#include "range/range.hpp"
#include "hemi.h"
#include "device_api.h"

using namespace util::lang;

// type alias to simplify typing...
template<typename T>
using step_range = typename range_proxy<T>::step_range_proxy;

namespace hemi {

	template <typename T>
	HEMI_DEV_CALLABLE_INLINE
	step_range<T> grid_stride_range(T begin, T end) {
	    begin += hemi::globalThreadIndex();
	    return range(begin, end).step(hemi::globalThreadCount());
	}
	
}
/////////////////////////////////////////////////////////////////