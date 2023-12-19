#include "subventana1.hpp"
#include <iostream>

subventana1::subventana1(/* args */)
{
    auto builder = Gtk::Builder::create_from_file("../ui/subventana1.ui");

    this->box_subventana1 = builder->get_widget<Gtk::Box>("box_subventana1");
    this->btn_message = builder->get_widget<Gtk::Button>("btn_message");

    this->set_default_size(300, 200);
    this->set_title("Ventana 1");
    this->set_child(*box_subventana1);

    this->set_hide_on_close(true);

    //signals
    btn_message->signal_clicked().connect(sigc::mem_fun(*this, &subventana1::on_btn_message_clicked));
}

void subventana1::on_btn_message_clicked()
{
    m_pDialog.reset(new Gtk::MessageDialog(*this, "This is an INFO MessageDialog"));
    m_pDialog->set_secondary_text(  "And this is the secondary text that explains things.");
    m_pDialog->set_modal(true);
    m_pDialog->set_hide_on_close(true);
    m_pDialog->signal_response().connect(sigc::hide(sigc::mem_fun(*m_pDialog, &Gtk::Widget::hide)));

    m_pDialog->show();
}

subventana1::~subventana1()
{
    std::cout << "Destruct Window 1" << std::endl;
}
