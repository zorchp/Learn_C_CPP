#include "CubeViewUI.h"

static int my_handler(int event) {
    if (event == FL_SHORTCUT) return 1;
    // eat all shortcut keys
    return 0;
}

int main(int argc, char **argv) {
    CubeViewUI ui;
    // Fl::add_handler(my_handler);
    // Fl::visual(FL_DOUBLE | FL_INDEX);
    ui.show(argc, argv);
    return Fl::run();
}