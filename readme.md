# Finance API (Drogon + PostgreSQL)

Backend experimental para estudo de **C++ com Drogon**, banco **PostgreSQL** e arquitetura de API.

Este documento explica **como clonar e rodar o projeto do zero** após baixar do GitHub.

---

# 1. Pré‑requisitos

Instale as ferramentas abaixo:

## Linux (Ubuntu / Debian)

```bash
sudo apt update

sudo apt install -y \
  build-essential \
  cmake \
  git \
  postgresql \
  postgresql-client \
  libpq-dev
```

Instalar Drogon:

```bash
git clone https://github.com/drogonframework/drogon
cd drogon
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install
```

Verificar instalação:

```bash
drogon_ctl --version
```

---

# 2. Clonar o projeto

```bash
git clone https://github.com/LzGuimaraes/finance-api.git
cd finance-api
```

---

# 3. Arquivos que NÃO estão no GitHub

Alguns arquivos são ignorados pelo `.gitignore` e precisam ser criados localmente.

Crie:

```
config.json
build/
logs/
```

---

# 4. Criar config.json

Copie o exemplo:

```bash
cp config.example.json config.json
```

Ou crie manualmente:

```json
{
  "listeners": [
    {
      "address": "0.0.0.0",
      "port": 8848,
      "https": false
    }
  ],

  "db_clients": [
    {
      "name": "default",
      "rdbms": "postgresql",
      "host": "127.0.0.1",
      "port": 5432,
      "dbname": "investments",
      "user": "finance_user",
      "passwd": "123456",
      "connection_number": 10
    }
  ]
}
```

---

# 5. Configurar PostgreSQL

Entrar no postgres:

```bash
sudo -u postgres psql
```

Criar usuário:

```sql
CREATE USER finance_user WITH PASSWORD '123456';
ALTER USER finance_user CREATEDB;
```

Criar banco:

```sql
CREATE DATABASE investments OWNER finance_user;
```

Sair:

```sql
\q
```

---

# 6. Rodar migrations

Executar todas as migrations:

```bash
for f in migrations/*.sql; do
  echo "Running $f"
  psql -U finance_user -d investments -f "$f"
done
```

Isso criará as tabelas necessárias.

---

# 7. Gerar models do Drogon

Se necessário regenerar:

```bash
drogon_ctl create model models
```

Ou usando `model.json`:

```bash
drogon_ctl create model model.json
```

---

# 8. Build do projeto

Criar pasta de build:

```bash
mkdir build
cd build
```

Compilar:

```bash
cmake ..
make -j$(nproc)
```

---

# 9. Rodar o servidor

Dentro de `build`:

```bash
./finance-api
```

Se tudo estiver correto aparecerá:

```
Servidor iniciado
```

API rodando em:

```
http://localhost:8848
```

---

# 10. Estrutura do projeto

```
finance-api

controllers/
services/
repositories/
models/

migrations/

config.example.json
model.json

main.cc
CMakeLists.txt

build/ (ignorado pelo git)
logs/ (ignorado pelo git)
```

---

# 11. Workflow de desenvolvimento

Atualizar projeto:

```bash
git pull
```

Compilar novamente:

```bash
cd build
make
```

Rodar:

```bash
./finance-api
```

---

# 12. Rodar novas migrations

Quando novas migrations forem adicionadas:

```bash
for f in migrations/*.sql; do
  psql -U finance_user -d investments -f "$f"
done
```

---

# 13. Troubleshooting

### Erro: Peer authentication failed

Execute postgres como root:

```bash
sudo -u postgres psql
```

ou configure um usuário com senha.

---

# 14. Objetivo do projeto

Este projeto é usado para estudo de:

* Drogon
* PostgreSQL
* Arquitetura Backend em C++
* APIs REST

---

# 15. Próximos passos

Planejado para o projeto:

* sistema de usuários
* portfólio de investimentos
* cálculo de posição
* API para integração com dashboards
