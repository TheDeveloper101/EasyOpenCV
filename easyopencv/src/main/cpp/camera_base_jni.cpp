/*
 * Copyright (c) 2020 OpenFTC Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <jni.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <android/native_window.h>
#include <android/native_window_jni.h>

using namespace cv;

extern "C" JNIEXPORT void JNICALL
Java_org_openftc_easyopencv_OpenCvCameraBase_nativeCopyMatToSurface(JNIEnv *env, jobject thiz, jlong handle, jlong buf)
{
    ANativeWindow* window = (ANativeWindow*)handle;
    Mat* mat = (Mat*)buf;

    ANativeWindow_Buffer nativeWindowBuffer;
    ANativeWindow_lock(window, &nativeWindowBuffer, NULL);

    memcpy(nativeWindowBuffer.bits, mat->data, mat->rows*mat->cols*4);

//    uint8_t* endOfBuff = mat->data + (mat->rows * mat->cols * 4);
//    uint8_t* startOfBuff = mat->data+3;
//    for(uint8_t* alphaPtr = startOfBuff; alphaPtr <= endOfBuff; alphaPtr+=4)
//    {
//        *alphaPtr = 255;
//    }

    ANativeWindow_unlockAndPost(window);
}

extern "C" JNIEXPORT jlong JNICALL
Java_org_openftc_easyopencv_OpenCvCameraBase_nativeGetSurfaceHandle(JNIEnv *env, jobject thiz, jobject surface)
{
    ANativeWindow* nativeWindow = ANativeWindow_fromSurface(env, surface);
    return (jlong) nativeWindow;
}

extern "C" JNIEXPORT void JNICALL
Java_org_openftc_easyopencv_OpenCvCameraBase_nativeReleaseSurfaceHandle(JNIEnv *env, jobject thiz, jlong handle)
{
    ANativeWindow_release((ANativeWindow*)handle);
}