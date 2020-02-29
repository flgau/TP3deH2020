// To do

#include <iomanip>

#include "debogageMemoire.h"
#include "Episode.h"


// To do
Episode::Episode()
    :numEpisode_(0)
{
}

// To do
Episode::Episode(unsigned int numEpisode, const std::string& nom, const std::string& duree)
    : numEpisode_(numEpisode)
    , nom_(nom)
    , duree_(duree)
{
}

// To do
bool Episode::operator==(unsigned int numEpisode)
{

    return numEpisode_ == numEpisode;
}

// To do
std::ostream& operator<<(std::ostream& os, const Episode& episode)
{
    return os << episode.numEpisode_ << episode.nom_ << episode.duree_;
}

// To do
std::istream& operator>>(std::istream& is, Episode& episode)
{
    return is >> episode.numEpisode_ >> episode.nom_ >> episode.duree_;
}

// To do
unsigned int Episode::getNumEpisode() const
{
    return numEpisode_;
}
std::string Episode::getNom() const
{
    return nom_;
}
std::string Episode::getDuree() const
{
    return duree_;
}