# Bio-Resonance : Synthétiseur Capacitif et Interface Tactile Interactive

**Auteur :** AYDI Youssef
**Groupe :** 1221FA

## 1. Description du Projet
Le projet **Bio-Resonance** est un instrument de musique électronique innovant basé sur le principe de la **détection capacitive**. Ce système transforme des objets conducteurs ou organiques (fruits, eau, papier graphite) en surfaces tactiles. En touchant ces objets, l'utilisateur modifie la capacité électrique du circuit, ce qui est interprété par l'Arduino pour générer des notes musicales en temps réel.

## 2. Motivation
L'objectif est d'explorer des interfaces Homme-Machine (HMI) créatives. Ce projet démontre comment des objets banals peuvent devenir des outils d'expression artistique. C'est également une solution d'assistance pour les personnes ayant des difficultés motrices, remplaçant les boutons mécaniques par des surfaces tactiles larges et naturelles.

## 3. Architecture du Système
Le système utilise un microcontrôleur **Arduino Uno** :
* **Entrées :** Réseau de résistances de 10M Ohms créant des capteurs capacitifs de haute sensibilité.
* **Traitement :** Analyse de la variation de charge électromagnétique lors du contact humain.
* **Sorties :** * Signal sonore via un **Buzzer passif**.
    * Feedback visuel via des **LEDs colorées** synchronisées.
    * Affichage des notes sur un **Écran LCD 16x2 (I2C)**.

## 4. Fonctionnement (Mode d'emploi)
1. L'utilisateur connecte des objets (ex: une banane, un verre d'eau) aux fils "crocodile".
2. Au toucher d'un objet, le circuit se ferme via le corps de l'utilisateur (capacité).
3. L'Arduino identifie l'objet touché et joue la note correspondante (Do, Ré, Mi...).
4. La LED associée s'allume et l'écran LCD affiche le nom de la note jouée.

## 5. Composants et Budget
| Composant | Rôle | Prix (RON) |
| :--- | :--- | :--- |
| Arduino Uno R3 (Clone) | Unité centrale de traitement | 42,50 |
| Écran LCD 1602 avec module I2C | Interface visuelle (Notes/Infos) | 24,90 |
| Résistances 10M Ohms (Pack) | Capteurs de toucher haute sensibilité | 3,50 |
| Buzzer Passif 5V | Génération des tonalités musicales | 5,20 |
| Pack 10 Câbles Crocodile | Connectique pour objets conducteurs | 19,90 |
| Set de 5 LEDs colorées | Feedback visuel de contact | 3,80 |
| Breadboard 830 points | Support pour montage sans soudure | 15,50 |
| Set de fils de saut (Jumpers) | Connexions internes du circuit | 11,50 |
| Connecteur Pile 9V / Jack | Alimentation portable | 4,50 |
| **TOTAL ESTIMÉ** | | **146,30 RON** ||

## 6. Logiciel
Le code repose sur la bibliothèque `CapacitiveSensor`. Un seuil de détection (threshold) est configuré pour filtrer les bruits parasites et garantir une réponse instantanée au toucher.
