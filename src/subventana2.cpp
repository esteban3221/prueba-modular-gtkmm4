#include "subventana2.hpp"
#include <iostream>

subventana2::subventana2(/* args */)
{
    auto builder = Gtk::Builder::create_from_file("../ui/subventana2.ui");

    this->box_subventana2 = builder->get_widget<Gtk::Box>("box_subventana2");
    this->pg_bar = builder->get_widget<Gtk::ProgressBar>("pg_bar");
    this->btn_tgl_pg = builder->get_widget<Gtk::ToggleButton>("btn_tgl_pg");

    this->set_default_size(300,200);
    this->set_title("Ventana 2");
    this->set_child(*box_subventana2);

    this->set_hide_on_close(true);

    m_connection_timeout = Glib::signal_timeout().connect(sigc::mem_fun(*this,  &subventana2::on_timeout), 50 );
    btn_tgl_pg->signal_toggled().connect(sigc::mem_fun(*this, &subventana2::on_checkbutton_activity) );
}

subventana2::~subventana2()
{
    g_info("Destruct Window 2");
}

void subventana2::on_checkbutton_activity()
{
  if(btn_tgl_pg->get_active())
    pg_bar->pulse();
  else
    pg_bar->set_fraction(0.0);
}

bool subventana2::on_timeout()
{
  if(pg_bar && btn_tgl_pg->get_active() == true)
    pg_bar->pulse();
  else
  {
    pg_bar->set_fraction(0.0);
    //return false para que ya no sea llamado
  }
  return true;
}
