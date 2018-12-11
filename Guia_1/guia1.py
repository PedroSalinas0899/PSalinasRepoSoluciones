import gi
gi.require_version('Gtk', '3.0')

from gi.repository import Gtk

class principal():
    def __init__(self):
        self.builder = Gtk.Builder()
        self.builder.add_from_file("guia1.glade")

        self.ventana = self.builder.get_object("ventana")
        self.ventana.set_default_size(800, 600)
        self.ventana.connect("destroy", Gtk.main_quit)

        self.txt1 = self.builder.get_object("txt1")
        self.txt2 = self.builder.get_object("txt2")
        self.largo = self.builder.get_object("largo")
        self.aceptar = self.builder.get_object("aceptar")
        self.reset = self.builder.get_object("reset")

        self.txt1.connect("activate", self.refrescar)
        self.txt1.connect("changed", self.refrescar)
        self.txt2.connect("activate", self.refrescar)
        self.txt2.connect("changed", self.refrescar)

        self.aceptar.connect("clicked", self.boton_aceptar)
        self.reset.connect("clicked", self.boton_reset)

        self.ventana.show_all()

    def refrescar(self, xd):
        txt1 = self.txt1.get_text()
        txt2 = self.txt2.get_text()

        self.largo.set_value(len(txt1) + len(txt2))

    def boton_aceptar(self, xd):
        a = ventana_emergente(self.txt1, self.txt2, self.largo)

    def boton_reset(self, xd):
        self.txt1.set_text("")
        self.txt2.set_text("")
        self.refrescar(xd)



class ventana_emergente():
    def __init__(self, txt1, txt2, large):
        self.texto1 = txt1
        self.texto2 = txt2
        self.lrg = large

        self.builder = Gtk.Builder()
        self.builder.add_from_file("guia1.glade")

        self.ventana2 = self.builder.get_object("ventana2")
        self.ventana2.set_default_size(800, 600)
        self.ventana2.connect("destroy", Gtk.main_quit)

        self.txtFinal = self.builder.get_object("txtFinal")
        self.largo = self.builder.get_object("largo")
        self.aceptar2 = self.builder.get_object("aceptar2")
        self.cancelar = self.builder.get_object("cancelar")

        textoFinal = self.texto1.get_text() + " " + self.texto2.get_text()
        largoFinal = len(textoFinal)

        self.txtFinal.set_value(textoFinal)
        self.largo.set_text(largoFinal)

        self.aceptar2.connect("clicked", self.boton_aceptar2)
        self.cancelar.connect("clicked", self.boton_cancelar)

        self.ventana.show_all()

    def boton_aceptar2(self, xd):
        self.texto1.set_text("")
        self.texto2.set_text("")
        self.lrgFinal.set_value(0)


        self.ventana2.destroy()

    def boton_cancelar(self, xd):
        self.ventana2.destroy()


if __name__ == "__main__":
    a = principal()
    Gtk.main()