/*  This file is part of The Firekylin Operating System.
 *
 *  Copyright 2016 Liuxiaofeng
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <stdint.h>

int64_t __divdi3(int64_t a, int64_t b)
{
	int64_t ret = 0;
	int sign1 = 0, sign2 = 0;

	if (a < 0) {
		sign1 = 1;
		a = -a;
	}
	if (b < 0) {
		sign2 = 1;
		b = -b;
	}
	if (b == 0)
		return (int64_t) -1;
	while (a > b) {
		a = a - b;
		ret++;
	}
	return (sign1 ^ sign2) ? -ret : ret;
}
