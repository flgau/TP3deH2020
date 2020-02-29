// To do
#include "Film.h"


// To do
Film::Film(Auteur* auteur)
    : Media(auteur,typeMedia_)
    , duree_("")
{
}

// To do
Film::Film(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
           bool estRestreintParAge, Auteur* auteur, const std::string& duree)
    :Media(nom,anneeDeSortie,genre,pays,estRestreintParAge,auteur,typeMedia_)
    ,duree_(duree)
{
}

// To do
std::ostream& Film::afficher(std::ostream& os) const
{
    return os << Media(nom_,
                       anneeDeSortie_,
                       genre_,
                       pays_,
                       estRestreintParAge_,
                       auteur_,
                       typeMedia_)
              << "Durée:" << duree_;
             
}

// To do
std::istream& Film::lire(std::istream& is)
{
    Media::lire(is);
    return is >> quoted(duree_);
}

// To do
std::unique_ptr<Media> Film::clone() const
{
    return std::make_unique<Media>(*this);
}
