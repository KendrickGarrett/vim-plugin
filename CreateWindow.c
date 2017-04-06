#include "window.h"int main (int argc, char** argv) {  struct MyWindow* mywindow = new ( MyWindow, 2 , 4);  mywindow->Clone(mywindow); return 0;}
