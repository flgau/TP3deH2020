// To do
#include "Serie.h"


// To do              Pointeur vers l'auteur du serie
Serie::Serie(Auteur* auteur)
    : Media(auteur, typeMedia_)
{
}

// To do
Serie::Serie(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
    bool estRestreintParAge, Auteur* auteur)
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, typeMedia_)
    , GestionnaireSaisons()
{
}

// To do
Serie::Serie(const Serie& serie)
    :Media(serie)
{
    // To do
}

// To do
std::ostream& Serie::afficher(std::ostream& os) const
{
    return os << Media(nom_,
        anneeDeSortie_,
        genre_,
        pays_,
        estRestreintParAge_,
        auteur_,
        typeMedia_);

}

// To do
std::unique_ptr<Media> Serie::clone() const
{
    return std::make_unique<Media>(*this);
}
