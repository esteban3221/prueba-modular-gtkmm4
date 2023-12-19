#include "ventana_main.hpp"
#include <iostream>

ventana_main::ventana_main()
{
    auto builder = Gtk::Builder::create_from_file("../ui/main.ui");
    //auto builder = Gtk::Builder::create_from_string("");

    //gtk:box gtk:grid... cualquier contenedor
    this->contenedor_main = builder->get_widget<Gtk::Box>("box_main_view");
    this->btn_ven_1 = builder->get_widget<Gtk::Button>("btn_ven_1");
    this->btn_ven_2 = builder->get_widget<Gtk::Button>("btn_ven_2");

    carga_senales();

    this->set_child(*contenedor_main);
    this->set_default_size(200,200);
}

void ventana_main::carga_senales(){
    btn_ven_1->signal_clicked().connect([this](){
        ventana1->show();
    });
    btn_ven_2->signal_clicked().connect([this](){
        ventana2->set_transient_for(*this);
        ventana2->set_modal(true);
        ventana2->show();
    });
}

ventana_main::~ventana_main()
{
}
