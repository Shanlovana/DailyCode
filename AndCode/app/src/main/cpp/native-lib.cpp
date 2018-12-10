#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_ming_com_andcode_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_ming_com_andcode_jni_JNIManage_setNums(JNIEnv *env, jobject instance, jint i) {

    // TODO

}extern "C"
JNIEXPORT jstring JNICALL
Java_ming_com_andcode_jni_JNIManage_getNums(JNIEnv *env, jobject instance) {

    // TODO
    std::string returnValue = "this is jnimanage text";

    return env->NewStringUTF(returnValue.c_str());
}