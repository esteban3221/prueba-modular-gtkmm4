#pragma once
#include <gtkmm.h>
#include "subventana1.hpp"
#include "subventana2.hpp"


class ventana_main : public Gtk::Window
{

protected:
    std::unique_ptr<subventana2> ventana2 = std::make_unique<subventana2>();
    std::unique_ptr<subventana1> ventana1 = std::make_unique<subventana1>();

private:
    Gtk::Box* contenedor_main = nullptr;
    Gtk::Button* btn_ven_1 = nullptr;
    Gtk::Button* btn_ven_2 = nullptr;

    void carga_senales();

public:
    ventana_main();
    ~ventana_main();
};