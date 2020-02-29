// To do
#include "Saison.h"


// To do
Saison::Saison()
    // To do
    :numSaison_(0),
    nbEpisodesmax_(0)
{
}

// To do
Saison::Saison(unsigned int numSaison, unsigned int nbEpisodemax)
    // To do
    :numSaison_(numSaison),
    nbEpisodesmax_(nbEpisodemax)
{
}

// To do
Saison::Saison(const Saison& saison)
    :numSaison_(saison.numSaison_),
    nbEpisodesmax_(saison.nbEpisodesmax_)
{
    for (unsigned int i = 0; i < saison.episodes_.size(); i++)
    {
        episodes_.push_back(std::make_unique<Episode>(*saison.episodes_[i].get()));
    }
}

// To do
Saison::~Saison()
{
    // To do
    episodes_.clear();
}

// To do
Saison& Saison::operator+=(std::unique_ptr<Episode> episode)
{
    if (trouverIndexEpisode(episode->getNumEpisode()) != EPISODE_INEXSISTANTE) // si l'episode n'est pas trouve
        *this -= trouverIndexEpisode(episode->getNumEpisode);
    
    episodes_.push_back(std::move(episode));
    sort(episodes_.begin(), episodes_.end(), Episode::SortByNumEpisode());
    return *this;
}

// To do
Saison& Saison::operator-=(unsigned int numEpisode)
{
    //if (trouverIndexEpisode(numEpisode) != EPISODE_INEXSISTANTE) // si l'episode n'est pas trouve
    episodes_.erase(episodes_.begin() + numEpisode);
    return *this;
    
}

// To do
bool Saison::operator==(unsigned int numSaison)
{
    return numSaison_ == numSaison;
}

// To do
std::ostream& operator<<(std::ostream& os, const Saison& saison)
{
    os << saison.numSaison_ << saison.getNbEpisodes;
    for (size_t i = 0; i < saison.episodes_.size(); i++)
    {
        os << saison.episodes_[i];
    }
    return os;
}

// To do
std::istream& operator>>(std::istream& is, Saison& saison)
{
    is >> saison.numSaison_ >> saison.getNbEpisodes;
    
    return is;
}

// To do
unsigned int Saison::getNumSaison() const
{
    return numSaison_;
}

// To do
size_t Saison::getNbEpisodes() const
{
    return episodes_.size();
}

// To do
size_t Saison::trouverIndexEpisode(unsigned int numEpisode)
{
    
    for (size_t i = 0; i < episodes_.size(); i++)
    {
        if (episodes_[i]->getNumEpisode() ==numEpisode)
            return i;
        
    }
    return EPISODE_INEXSISTANTE;
}