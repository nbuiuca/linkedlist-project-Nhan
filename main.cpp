/*
 TODO:(student) Add a comment header for the program here.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
//using namespace std;
/**
 * @brief Searches for a given string value in a list of strings.
 *
 * This is a helper function that searches for a given string value
 * in a list of strings using the standard library find function.
 *
 * Interestingly, the standard list class does not have a find method.
 *
 * @param myList The list to search in.
 * @param value The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool find(const std::list<std::string> &myList, const std::string &value)
{
    bool found = (std::find(myList.begin(),
                            myList.end(),
                            value) != myList.end());
    return found;
}

/**
 * @brief Reads, updates, and writes a list of movies.
 *
 * This function reads in a list of movies from a file,
 * adds new movies to the list, removes movies from the list,
 * and outputs the updated list to a file.
 *
 * @return int The exit status of the program.
 */
void readMoviesFromFile(const std::string& filename, std::list <std::string>& movies) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File " << filename << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string movie;
    while (getline(file, movie)) { // read every single line from file then store to movie
        movies.push_back(movie);
    }
    file.close();
}
void addMoviesFromFile(const std::string& filename, std::list<std::string>& movies) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File " << filename << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string movie;
    while (std::getline(file, movie)) {
        if (!find(movies, movie)) {
            movies.push_back(movie);
        }
        else {
            std::cout << "Movie " << movie << " cannot be added to the list." << std::endl;
        }
    }
    file.close();
}
void removeMoviesFromFile(const std::string& filename, std::list <std::string>& movies) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File " << filename << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string movie;
    while (std::getline(file, movie)) {
 
        if (find(movies.begin(), movies.end(), movie) != movies.end()) {
            movies.erase(find(movies.begin(), movies.end(), movie)); // erase the duplicate
        }
        else {
            std::cout << "Movie " << movie << " cannot be removed from the list." << std::endl;
        }
    }
}
void writeMoviesToFile(const std::string& filename, const std::list<std::string>& movies) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "File " << filename << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
    for (const auto& movie : movies) { //Each movie in the movies list is accessed one by one,iterate through all elements in movies 
        file << movie << std::endl; //write the movie to the file
    }
    file.close();
}
int main()
{
    // Follow instructions in project assignment
    std::list<std::string> movies;
    std::cout << "Reading in BearFlix movie list..." << std::endl;
    readMoviesFromFile("mymovies.txt", movies);
    std::cout << "Adding new movies..." << std::endl;
    addMoviesFromFile("add_movies.txt", movies);
    std::cout << "Removing movies..." << std::endl;
    removeMoviesFromFile("del_movies.txt", movies);
    std::cout << "New movie list ready!" << std::endl;
    writeMoviesToFile("mymovies_updated.txt", movies);
    return EXIT_SUCCESS;
}
