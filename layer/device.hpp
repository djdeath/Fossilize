/* Copyright (c) 2018 Hans-Kristian Arntzen
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include "dispatch_helper.hpp"
#include <string>

namespace Fossilize
{
class Instance;
class StateRecorder;
class Device
{
public:
	void init(VkPhysicalDevice gpu, VkDevice device,
	          Instance *pInstance,
	          const VkPhysicalDeviceFeatures2 &features,
	          VkLayerDispatchTable *pTable);

	VkLayerDispatchTable *getTable()
	{
		return pTable;
	}

	StateRecorder &getRecorder()
	{
		return *recorder;
	}

	VkDevice getDevice() const
	{
		return device;
	}

private:
	VkPhysicalDevice gpu = VK_NULL_HANDLE;
	VkDevice device = VK_NULL_HANDLE;
	VkLayerInstanceDispatchTable *pInstanceTable = nullptr;
	VkLayerDispatchTable *pTable = nullptr;

	StateRecorder *recorder = nullptr;

#ifdef ANDROID
	std::string serializationPath = "/sdcard/";
#else
	std::string serializationPath = "";
#endif
};
}
