#include "Resources.h"
#include "SDL_macros.h"

vector<Resources::FontInfo> Resources::fonts_{
	//
	{Basic, ARIAL12, "../AnimalCooking/resources/fonts/ARIAL.ttf", 12 }
};

	
	

vector<Resources::ImageInfo> Resources::images_{
	//
	{Basic, Button,"../AnimalCooking/resources/images/button.jpg"},

	{Basic, IngredienteMalo,"../AnimalCooking/resources/images/caca.png"},
	{Basic, Cooker,"../AnimalCooking/resources/images/sarten.png"},
	{Basic, CookerCooking,"../AnimalCooking/resources/images/sartencocinando.png"},
	{Basic, CookerCooked,"../AnimalCooking/resources/images/sartencooked.png"},
	{Basic, CookerBurned,"../AnimalCooking/resources/images/sartenburned.png"},
	{Basic, Platera,"../AnimalCooking/resources/images/platera.png"},
	{Basic, ComidaCocinada,"../AnimalCooking/resources/images/comidaCocinada.jpg"},
	{Basic, Tomato,"../AnimalCooking/resources/images/tomato.png"},
	{Basic, Onion,"../AnimalCooking/resources/images/onion.png"},
	{Basic, Cuchillo,"../AnimalCooking/resources/images/cuchillo.png"},
	{Basic, CuchilloSucio,"../AnimalCooking/resources/images/cuchilloSucio.jpg"},
	{Basic, Fregadero,"../AnimalCooking/resources/images/fregadero.jpg"},
	{Basic, Hierba,"../AnimalCooking/resources/images/hierba.jpg"},
	{Basic, Ingrediente,"../AnimalCooking/resources/images/ingrediente.png"},
	{Basic, Panera,"../AnimalCooking/resources/images/panera.png"},
	{Basic, Papelera,"../AnimalCooking/resources/images/papelera.png"},
	{Basic, Pedido,"../AnimalCooking/resources/images/pedido.png"},
	{Basic, Cerdo,"../AnimalCooking/resources/images/personaje.png"},
	{Basic, Pollo,"../AnimalCooking/resources/images/personaje2.png"},
	{Basic, Plato,"../AnimalCooking/resources/images/plato.png"},
	{Basic, Repisa,"../AnimalCooking/resources/images/repisa.png"},
	{Basic, Suelo,"../AnimalCooking/resources/images/suelo.png"},
	{Basic, CuadradoAux,"../AnimalCooking/resources/images/cuadrado.png"},

	//FeedBack
	{Basic, TomatoFeedBack,"../AnimalCooking/resources/images/feedbackTomate.png"},
	{Basic, OnionFeedBack,"../AnimalCooking/resources/images/onionFeedBack.png"},
	{Basic, CuchilloFeedBack,"../AnimalCooking/resources/images/cuchilloFeedBack.png"},
	{Basic, PlatoFeedBack,"../AnimalCooking/resources/images/platoFeedBack.png"},
	{Basic, Panel,"../AnimalCooking/resources/images/panel.png"},

	{Basic, Pan,"../AnimalCooking/resources/images/pan.png"},
	{Basic, Aceite,"../AnimalCooking/resources/images/aceite.png"},
	{Basic, Arroz,"../AnimalCooking/resources/images/arroz.png"}
};

vector<Resources::TextMsgInfo> Resources::messages_{
	//

};

vector<Resources::MusicInfo> Resources::musics_{
	//

};

vector<Resources::SoundInfo> Resources::sounds_{
	//

};

