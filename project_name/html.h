// Page HTML
const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Interface utilisateur distributeur</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 20px;
      text-align: center;
    }

    h1 {
      color: #333;
    }

    button {
      padding: 10px;
      font-size: 16px;
      margin-top: 10px;
    }

    input {
      padding: 8px;
      font-size: 14px;
    }

    #selectedTime {
      margin-top: 20px;
    }

    #percentage {
      margin-top: 10px;
    }
  </style>
</head>
<body>

  <h1>Interface utilisateur distributeur</h1>

  <button id="doseCroquetteButton" onclick="doseCroquette()">Dose croquette</button>

  <button id="couvercleButton" onclick="actionCouvercle()">Couvercle</button>


  <!-- Afficher l'heure sélectionnée ici -->
  <div>
    <label for="timeInput">Heure de distribution programmée</label>
    <label id="selectedTime">%HEURE_SELECTIONNEE%</label>
  </div>


  <div>
    <label for="timeInput">Changer l'heure de distribution</label>
    <input type="time" id="timeInput">
    <button id="applyButton" onclick="appliquerHeure()">Appliquer</button>
  </div>


  <div id="percentage">Niveau de croquette : <span id="croquetteLevel">%NIVEAU_CROQUETTE%</span></div>

  <script>
   function appelServeur(url, callback) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
       if (callback) {
         callback(this);
        }
      }
    };
      xhttp.open("GET", url, true);
      xhttp.send();
  }

    function mettreAJourNiveauCroquette(nouveauNiveau) {
      // Exécutez des actions pour mettre à jour l'élément HTML du niveau de croquette
      // Par exemple, mettez à jour le contenu du span avec l'id "croquetteLevel"
      var croquetteLevelSpan = document.getElementById('croquetteLevel');
      // Obtenez le nouveau niveau de croquette du serveur (vous pouvez également stocker le niveau localement)
      // Mettez à jour le contenu de l'élément HTML
      croquetteLevelSpan.innerText = nouveauNiveau;
    }

    function traiteReponseDose(xhttp) {
      console.log("Dose de croquette effectuée !");
      var nouveauNiveau = xhttp.responseText;
      // Mettez à jour le niveau de croquette en appelant une fonction qui met à jour l'élément HTML correspondant
      mettreAJourNiveauCroquette(nouveauNiveau);
    }

    function doseCroquette() {
       appelServeur('/doseCroquette', traiteReponseDose);
    }

    function actionCouvercle() {
    // Envoi de la requête pour l'action "Couvercle" au serveur
    appelServeur('/actionCouvercle', traiteReponseCouvercle);
    }

    function traiteReponseCouvercle(xhttp) {
      console.log("Action 'Couvercle' effectuée !");
      // Vous pouvez traiter la réponse du serveur ici si nécessaire
    }

    function appliquerHeure() {
    var selectedTime = document.getElementById('timeInput').value;
    document.getElementById('selectedTime').innerText = selectedTime;

    // Envoi de l'heure mise à jour au serveur
    envoyerHeure(selectedTime);
  }

  function envoyerHeure(heure) {
    // Envoi de l'heure au serveur via une requête HTTP
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        // Réponse du serveur (si nécessaire)
        console.log("Heure envoyée avec succès !");
      }
    };
    xhttp.open("GET", "/updateHeure?heure=" + encodeURIComponent(heure), true);
    xhttp.send();
  }
  </script>

</body>
</html>
)=====";