// Copyright(c) 2024, Pete Brubaker <pete.brubaker@intel.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <vector>
#include <immintrin.h>

using std::vector;

namespace Types
{
	// regular unaligned Vector3
	struct Vector3
	{
		float x, y, z;
	};

	// aligned vector
	struct alignas(16) Vector3_SSE
	{
		__m128 m_vec;
	};

	// SSE functions
	void DotProduct_HADD(vector<float>& dst, const Vector3_SSE* __restrict src, size_t N);
	void DotProduct_DPPS(vector<float>& dst, const Vector3_SSE* __restrict src, size_t N);
	void DotProduct_SHUFFLE(vector<float>& dst, const Vector3_SSE* __restrict src, size_t N);
}