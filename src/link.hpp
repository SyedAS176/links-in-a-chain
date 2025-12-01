#include <string>

class Link {
  private:
    std::string material;

  public:
    Link(std::string material) {
      this->material = material;
    }

    std::string get_material() const {
      return this->material;
    }
};