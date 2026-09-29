# PSoC Embedded Systems

> Collection de projets pédagogiques autour du **C embarqué, de l'acquisition, du contrôle et de la communication sur PSoC**.  
> **English version below.**

## 🇫🇷 Vue d'ensemble

Ce dépôt regroupe plusieurs travaux réalisés sur PSoC afin de montrer une progression allant des fondamentaux du C embarqué jusqu'au contrôle de systèmes physiques et à l'IoT.

| Projet | Sujet | Éléments clés |
|---|---|---|
| `uart-fibonacci` | C embarqué & UART | récursivité, `static`, `extern`, pile, UART, retarget `printf/scanf` |
| `motor-vf-control` | Commande V/f d'une machine asynchrone | ADC, PWM, interruption, six signaux de commande, variation de fréquence |
| `solar-mppt` | Commande MPPT photovoltaïque | mesures tension/courant, ADC, PWM, calcul de puissance, recherche du MPP |
| `iot-node-red` | Chaîne IoT PSoC → Node-RED | ADC, UART, JSON, parsing, dashboard |

Le projet Fibonacci était auparavant présenté seul. Il reste conservé comme exercice pédagogique, mais cette collection reflète mieux les usages du microcontrôleur : **mesurer, commander et communiquer**.

## 1. UART / Fibonacci

Projet sur PSoC 5LP utilisant Fibonacci comme support pour étudier le C embarqué : versions itérative et récursive, tableaux statiques, compteur local `static`, variable partagée avec `extern`, observation de la pile et communication UART avec un PC.

Les sources historiques sont conservées dans `src/`.

## 2. Commande moteur V/f

Projet PSoC Creator consacré à la génération de commandes PWM pour une machine asynchrone.

Chaîne fonctionnelle :

`potentiomètre → ADC → interruption → calcul période/rapport → PWM déphasées → commande moteur`

Le code retrouvé dans l'archive pilote trois blocs PWM et met à jour leurs périodes et comparaisons depuis une mesure ADC. Les valeurs de comparaison créent les déphasages nécessaires aux signaux de commande.

Les sources applicatives récupérées sont publiées dans `motor-vf-control/src/`. Les fichiers générés automatiquement par PSoC Creator et les artefacts de compilation ne sont pas inclus.

## 3. MPPT photovoltaïque

Travail réalisé avec un PSoC autour du suivi du point de puissance maximale d'un panneau photovoltaïque.

Chaîne étudiée :

`panneau PV → mesure tension/courant → conditionnement → ADC → calcul puissance → commande MPPT → PWM`

Le projet archivé confirme l'utilisation de deux ADC, d'un conditionnement analogique, d'une PWM et d'une logique de recherche du point de puissance maximale documentée dans le compte rendu.

**Transparence :** l'archive PSoC retrouvée contient bien le projet et des sources applicatives, mais la version de `fonction.c` conservée dans cette archive ne contient que l'initialisation des composants. L'algorithme MPPT détaillé dans le rapport n'est donc pas reconstruit artificiellement dans ce dépôt.

## 4. PSoC + Node-RED

Mini-projet IoT reliant un PSoC à Node-RED :

`potentiomètre → ADC PSoC → UART → JSON → Node-RED → parsing → graphique/jauge`

Le travail a évolué d'une valeur série brute vers une trame JSON, puis vers le transport de plusieurs valeurs dans une même trame. Cette partie est documentée à partir du TP archivé ; elle sert surtout à illustrer le lien entre embarqué, communication et visualisation de données.

## Sécurité et nettoyage

Les chemins locaux, logs de compilation et fichiers générés par PSoC Creator ne sont pas publiés. Le dépôt privilégie les sources applicatives et une documentation fidèle aux archives.

---

# 🇬🇧 PSoC Embedded Systems

This repository groups several educational PSoC projects covering **embedded C, data acquisition, control and communication**.

- **UART / Fibonacci:** recursion, static storage, call stack and UART communication.
- **Motor V/f control:** ADC-driven PWM generation and phase-shifted control signals for an induction-motor exercise.
- **Solar MPPT:** voltage/current acquisition, analog conditioning, PWM and maximum-power-point tracking study.
- **PSoC + Node-RED:** ADC data sent over UART as JSON and displayed in a Node-RED dashboard.

The repository intentionally keeps the historical student code authentic. Generated PSoC Creator sources, build outputs and machine-specific paths are excluded. When an archived source is incomplete, the documentation says so instead of reconstructing code and presenting it as original.
