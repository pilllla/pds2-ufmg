#ifndef PDS2_ESTUDANTE_H
#define PDS2_ESTUDANTE_H

#include "pessoa.h"

class Estudante : public Pessoa {
private:
  unsigned int _matricula;
public:
  Estudante(
    std::string nome,
    unsigned long cpf,
    unsigned int matricula
  );
  unsigned int get_matricula() const;
  virtual Acesso acesso_moodle() const override;
};

#endif
