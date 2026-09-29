# Fibonacci sur PSoC 5LP — C embarqué & UART

> Projet académique réalisé dans le cadre de la programmation C pour l'embarqué.  
> **English version below.**

## 🇫🇷 Présentation

Ce projet explore plusieurs notions fondamentales du **C embarqué sur PSoC 5LP** à partir du calcul de la suite de Fibonacci : implémentations itérative et récursive, allocation statique, portée des variables, pile d'appels et communication UART avec un PC.

L'application attend une commande reçue par UART. Lorsque le caractère `F` est saisi, la version itérative est exécutée. Un compteur local `static` compte les appels et un drapeau global déclenche l'envoi des résultats après la 100e exécution.

## Fonctionnalités

- Fibonacci **itératif et récursif** ;
- stockage des résultats dans des tableaux statiques ;
- comparaison des approches et observation de la pile en debug ;
- compteur local `static` persistant entre les appels ;
- partage d'un drapeau global via `extern` ;
- communication **UART PSoC ↔ PC** ;
- redirection de `printf` et `scanf` vers l'UART avec `_write` / `_read` ;
- attente de `UART_1_TX_STS_COMPLETE` avant de poursuivre après l'envoi.

## Organisation

```text
src/
├── main.c        # Boucle principale, UART et affichage
├── fonction.c    # Calculs Fibonacci et compteur d'exécutions
├── fonction.h    # Interface des fonctions et variable externe
└── utilitaire.c  # Retarget printf/scanf vers l'UART
```

## Technologies

- **C**
- **PSoC Creator**
- **PSoC 5LP**
- UART
- types Cypress `uint8`, `uint16`, `uint32`
- PuTTY pour les essais de liaison série

## Point intéressant

Le projet ne se limite pas au calcul de Fibonacci : celui-ci sert de support pour observer des problématiques propres à l'embarqué, notamment la différence de comportement mémoire entre une solution itérative et une solution récursive, ainsi que la communication avec un terminal externe.

## État

Le dossier `src/` provient du projet PSoC archivé. Les fichiers générés automatiquement par PSoC Creator et les artefacts de compilation ne sont volontairement pas versionnés.

---

# 🇬🇧 Fibonacci on PSoC 5LP — Embedded C & UART

## Overview

Academic embedded-C project built on a **PSoC 5LP**. Fibonacci is used as a practical case to explore iterative and recursive algorithms, static storage, variable scope, call-stack behavior and UART communication with a PC.

The application receives commands through UART. When `F` is entered, the iterative implementation runs. A local `static` counter tracks calls and a shared flag triggers result transmission after the 100th execution.

## Features

- iterative and recursive Fibonacci implementations;
- statically allocated result arrays;
- call-stack observation during debugging;
- persistent local `static` counter;
- global flag shared with `extern`;
- PSoC-to-PC UART communication;
- `printf` / `scanf` retargeting through `_write` and `_read`;
- UART transmission-complete status handling.

## Technologies

**C · PSoC Creator · PSoC 5LP · UART · PuTTY**

## Repository

The `src/` directory contains the archived application source code. Generated PSoC Creator files and build artifacts are intentionally excluded to keep the repository focused on the implementation.
