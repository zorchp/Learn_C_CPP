// generated by Fast Light User Interface Designer (fluid) version 1.0308

#include "use-chinese.h"

Hello::Hello() {
  { win = new Fl_Double_Window(297, 248, "\344\275\240\345\245\275\344\270\226\347\225\214");
    win->user_data((void*)(this));
    { text = new Fl_Text_Display(120, 84, 50, 30, "\344\275\240\345\245\275\344\270\226\347\225\214\357\274\201^\350\277\231\
\351\207\214\346\230\257""FLTK\344\270\255\346\226\207\347\225\214\351\235\
\242");
      text->box(FL_PLASTIC_DOWN_FRAME);
      text->color(FL_FOREGROUND_COLOR);
      text->labelfont(3);
      text->labelsize(17);
      text->labelcolor((Fl_Color)90);
    } // Fl_Text_Display* text
    win->end();
  } // Fl_Double_Window* win
}

void Hello::show(int argc, char**argv) {
  win->show(argc, argv);
}
