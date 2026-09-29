# PSoC + Node-RED

## 🇫🇷

Mini-projet IoT réalisé autour d'un PSoC et de Node-RED.

### Chaîne de données

`potentiomètre → ADC PSoC → UART → JSON → Node-RED → parsing → dashboard`

Le TP commence par un flow HTTP simulant des mesures au format JSON, puis passe à un système matériel : une entrée analogique PSoC est convertie par ADC et transmise sur le port série. Node-RED lit ensuite la liaison série et affiche la mesure sous forme de graphique et de jauge.

Une évolution du projet remplace la donnée brute par une trame JSON puis transporte deux valeurs dans une même trame.

### Technologies

C embarqué · PSoC · ADC · UART · JSON · Node-RED · dashboard

### Disponibilité des sources

Cette partie est documentée depuis le compte rendu archivé. Les sources PSoC/flows Node-RED complets correspondant exactement à cette version n'ont pas été identifiés avec suffisamment de certitude pour être publiés ici.

---

## 🇬🇧

Small IoT exercise connecting a PSoC board to Node-RED.

The data path is:

`potentiometer → PSoC ADC → UART → JSON → Node-RED → parsing → dashboard`

The exercise progressed from raw serial data to JSON frames and finally to multiple values carried in a single frame. This folder documents the verified workflow; complete matching source/flow files have not been identified with enough certainty to publish them as original.
