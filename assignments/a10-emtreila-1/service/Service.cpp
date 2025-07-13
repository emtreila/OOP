#include "Service.h"

#include "../action/ActionAdd.h"
#include "ServiceException.h"
#include "../action/ActionRemove.h"
#include "../action/ActionUpdate.h"


void Service::addCoatService(const std::string &size,
                             const std::string &colour,
                             double price,
                             unsigned int quantity,
                             const std::string &photo) {
    /**
     * Adds the coat to the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @param quantity - the quantity of the coat
     * @param photo - the photo of the coat
     * @return true if the coat was added, false otherwise
     */
    TrenchCoat newCoat = TrenchCoat(size, colour, price, quantity, photo);
    try {
        ValidatorTrenchCoat::validateTrenchCoat(newCoat);
    } catch (const ValidatorException &e) {
        std::string errorMessage = "The trench coat is not valid: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }

    try {
        this->repo->addCoat(newCoat);
    } catch (const RepositoryException &e) {
        std::string errorMessage = "The trench coat could not be added: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
    undoStack.push_back(std::make_unique<ActionAdd>(*repo, newCoat));
    redoStack.clear();
}

void Service::removeCoatService(const std::string &size, const std::string &colour) {
    /**
     * Removes the coat from the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @return true if the coat was removed, false otherwise
     */
    try {
        ValidatorTrenchCoat::validateSize(size);
        ValidatorTrenchCoat::validateColour(colour);
    } catch (const ValidatorException &e) {
        std::string errorMessage = "The size / colour is not valid: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }

    TrenchCoat removedCoat;
    bool found = false;
    for (const auto &coat: this->repo->getAll()) {
        if (coat.getSize() == size && coat.getColour() == colour) {
            removedCoat = coat;
            found = true;
            break;
        }
    }
    if (!found) {
        throw ServiceException("The coat does not exist!");
    }

    try {
        this->repo->removeCoat(size, colour);
    } catch (const RepositoryException &e) {
        std::string errorMessage = "The trench coat could not be removed: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
    undoStack.push_back(std::make_unique<ActionRemove>(*repo, removedCoat));
    redoStack.clear();
}

void Service::updateCoatService(const TrenchCoat &coat) {
    /**
     * Updates the coat from the repository
     * @param coat - the coat to be updated
     * @return true if the coat was updated, false otherwise
     */
    try {
        ValidatorTrenchCoat::validateTrenchCoat(coat);
    } catch (const ValidatorException &e) {
        std::string errorMessage = "The trench coat is not valid: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
    TrenchCoat oldCoat;
    bool found = false;
    for (const auto &existingCoat: this->repo->getAll()) {
        if (existingCoat == coat) {
            // match by size + colour
            oldCoat = existingCoat;
            found = true;
            break;
        }
    }

    if (!found) {
        throw ServiceException("The coat to update does not exist!");
    }

    try {
        this->repo->updateCoat(coat);
    } catch (const RepositoryException &e) {
        std::string errorMessage = "The trench coat could not be updated: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
    undoStack.push_back(std::make_unique<ActionUpdate>(*repo, oldCoat, coat));
    redoStack.clear();
}

const std::vector<TrenchCoat> &Service::getAllService() const {
    /**
     * Gets all the coats from the repository
     * @return a vector of coats
     */
    return this->repo->getAll();
}

void Service::addAction(std::unique_ptr<Action> action) {
    this->redoStack.clear();
    this->undoStack.push_back(std::move(action));
}

void Service::undo() {
    if (this->undoStack.empty())
        return;

    auto action = std::move(this->undoStack.back());
    this->undoStack.pop_back();
    action->executeUndo();
    redoStack.push_back(std::move(action));
}

void Service::redo() {
    if (this->redoStack.empty())
        return;

    auto action = std::move(this->redoStack.back());
    this->redoStack.pop_back();
    action->executeRedo();
    this->undoStack.push_back(std::move(action));
}
