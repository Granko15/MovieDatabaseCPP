
Semestrálny projekt

téma: Filmová databáza
autor: Matúš Granec

stručný popis projketu:

Hlavná idea projektu bola vytvoriť si a udržiavať filmovú databázu,
vytvoriť užívateľov a užívateľovi aj watchlist filmov, ktoré videl, alebo si 
plánuje pozrieť s tým, že ak by užívateľ chcel, dostane aj odporúčania na filmy,
podľa svojich preferencií.

Popis tried a ich metód:

class Film:

	Každý film má základné atribúty Title, Rating, Year, Seen a mapu kategórií do ktorých spadá.


	void Film::setDefaultCategories(const std::string &filename):
		
		metóda je zavolaná pri konštruktore filmu.
		načíta základnú mapu kategórií pre každý film.
		kľúč = názov kategórie
		value = false/true


	std::string Film::putTitle(std::string movieTitle):
		
		nastaví Title pre film


	int Film::putYear(int movieYear):
		
		skontroluje a nastaví rok kedy bol film natočený

	
	double Film::putRating(double movieRating):

		skontroluje a nastaví hodnotenie filmu


	bool Film::addCategory(std::string movieCategory):

		skontroluje, či sa kategória už nenachádza v mape kategóríí
		skontroluje aj či sa v mape nachádza názov kategórie
		a nastaví kategóriu na true


	std::string Film::getCategory(const std::string categoryName):	

		skontroluje, či film patrí do danej kategórie a vráti názov tejto kategórie


	std::string Film::getCategories():

		vráti zoznam všetkých kategórií filmu, kategórie sú oddelené čiarkou

	
class Viewer:

	Každý viewer má základné atribúty Nickname, favoriteMovies a favoriteEra.


	std::string Viewer::putNickname(const std::string viewerNick):
		
		skontroluje a nastaví prezývku viewera
		povolené znaky sú písmená a čísla.

	
	std::string Viewer::putFavMovie(const std::string favMovie):

		pridá do vectoru obľúbených filmov názov filmu.

		
	int Viewer::putFavEra(int favEra):
		
		nastaví viewerovi obľúbený rok kedy boli natočené filmy.


	std::string Viewer::getFavMovies():

		vráti zoznam názvov všetkých obľúbených filmov, názvy sú oddelené čiarkou


class FilmDatabase:

	Databáza má atribút std::map<std::string , Film> filmMap

	
	bool FilmDatabase::readFilmsFromFile(const std::string &filename):

		zo súboru sa do databázy načítajú všetky filmy, ktoré sa uložia do mapy
		key = názov filmu
		value = trieda Film

	
	void FilmDatabase::printOutFilms():
		
		kontrolný výpis načítanej/vytvorenej databázy filmov


	Film FilmDatabase::getFilm(const std::string filmTitle):

		vráti smerník na film z databázy s daným názvom
		ak film v databáze nie je vráti nullptr


	std::vector<Film*> FilmDatabase::getFilmsOfEra(int favYear):

		vráti vector smerníkov na filmy z databázy, ktoré boli natočené
		v danom desaťročí.


	std::vector<Film*> FilmDatabase::getFilmsOfCategory(std::string favCategory):

		vráti vector smerníkov na filmy z databázy, ktoré spadajú
		do danej kategórie.


class Watchlist:

	Watchlist má atribúty myWatchlist, database, viewer


	Watchlist::Watchlist(Viewer viewer):
	
		presunie pomocou move inštanciu triedy Viewer do atribútu viewer v tried Watchlist

	
	void Watchlist::printOutDatabase():
		
		kontrolný výpis atribútu database, na sledovanie toho, či nastanú zmenu ako v atribúte
		database tak aj v atribúte myWatchlist.


	void Watchlist::printRecommendations():

		výpis vectora myWatchlist, nachádzajú sa tu filmy, ktoré boli práve odporučené,
		alebo si ich tam užívateľ pridal.


	void Watchlist::addFilmToWatchlist(Film *film):


		pridávanie filmov do vectora myWatchlist, ak bol film už videný,
		tak ho nepridá.


	Film* Watchlist::getFilmFromList(const std::string filmTitle):

		metóda vráti smerník na daný film z myWatchlist,
		ak sa film vo watchliste nenachádza, vráti nullptr


	void Watchlist::addFilmWithCat(std::string category):
		
		prepíše myWatchlist a pridá doň filmy, ktoré spadajú do danej kategórie
		vráti myWatchlist


	void Watchlist::addFilmOfEra(int era):

		prepíše myWatchlist a pridá doň filmy, ktoré sú z daného desaťročia
		vráti myWatchlist


	void Watchlist::markAsSeen(std::string filmTitle):
		
		označí daný film ako videný, nastavuje to aj filmu v databáze ako aj
		myWatchliste





