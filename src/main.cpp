#include <gtkmm.h>
#include "ventana_main.hpp"

int main(int argc, char *argv[])
{ 
    auto app = Gtk::Application::create("org.gtkmm.example");
    return app->make_window_and_run<ventana_main>(argc, argv);

}