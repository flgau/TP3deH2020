// To do
#include "GestionnaireSaisons.h"

// To do
GestionnaireSaisons::~GestionnaireSaisons()
{
    saisons_.clear();
}

// To do
GestionnaireSaisons& GestionnaireSaisons::operator+=(std::unique_ptr<Saison> saison)
{
    // To do
    if (trouverIndexSaison(saison->getNumSaison()) != SAISON_INEXSISTANTE) // si l'episode n'est pas trouve
        *this -= trouverIndexSaison(saison->getNumSaison);

    saisons_.push_back(std::move(saison));
    sort(saisons_.begin(), saisons_.end(), Saison::SortByNumSaison());
    return *this;
}

// To do
GestionnaireSaisons& GestionnaireSaisons::operator-=(const unsigned int numSaison)
{
    // To do
    saisons_[trouverIndexSaison(numSaison)] = std::move(saisons_[saisons_.size()]);
    saisons_.pop_back();
    return *this;
}

// To do
void GestionnaireSaisons::ajouterEpisode(const unsigned int numSaison,
                                         std::unique_ptr<Episode> episode)
{
    *saisons_[trouverIndexSaison(numSaison)] += std::move(episode);
    sort(saisons_.begin(), saisons_.end(), Saison::SortByNumSaison());


}

// To do
void GestionnaireSaisons::retirerEpisode(const unsigned int numSaison,
                                         const unsigned int numEpisode)
{
    // To do
    *saisons_[trouverIndexSaison(numSaison)] -= numEpisode;
}

/// To do
size_t GestionnaireSaisons::trouverIndexSaison(const unsigned int numSaison) const
{
    // To do
    for (size_t i = 0; i < saisons_.size(); i++)
    {
        if (saisons_[i]->getNumSaison() == numSaison)
            return i;

    }
    return SAISON_INEXSISTANTE;
}

// To do
Saison* GestionnaireSaisons::getSaison(const unsigned int numSaison) const
{
    return saisons_[trouverIndexSaison(numSaison)].get();
}

// To do
size_t GestionnaireSaisons::getNbSaisons() const
{
    // To do
    return saisons_.size();
}
/*std::ostream& GestionnaireSaisons::afficher(std::ostream& os){

}*/
