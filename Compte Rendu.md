Setuo-Dump-Database-Logs

La commande qui permet de modifier la taille d'un fichier est la suivante:
truncate [option] <taille> $logfile

Du coup si on veut supprimer les données d'un fichier lorsqu'il atteint 500Kb 
if [ "$logfile" -gt 500 ] 
then 
    truncate -s 0 $logfile
    
fi

==============================================================================

Setuo-Dump-Database-Service


J'actualise le systeme avec :
sudo systemctl daemon-reload

Et je passe en lancant le service
sudo systemctl start dump-database.service

Ainsi je passe en activant le timer
sudo systemctl enable dump-database.timer

===============================================================================

Dump-Database-Timer

Je commence d'abord par créer le timer:
sudo touch /etc/systemd/system/dump-database.timer

Aprés je lance le VI et je mets ce qui suit:
sudo vi /etc/systemd/system/dump-database.timer

Puis je rédige le script :
[Unit]
Description=Run backup every 10min

[Timer]
OnCalendar=*:0/10
AccuracySec=1s
Unit=dump-database.service

[Install]
WantedBy=timer.target

================================================================================

Dump-Database-Service

Je commence par créer le service :
sudo touch /etc/systemd/system/dump-database.service

Et je lance après le VI pour le rédiger
sudo vi /etc/systemd/system/dump-database.service

Ensuite rédige le script suivant :
[Unit]
Description=backup database

[Service]
ExecStart=/home/nath/dump-database.sh

================================================================================

Setup-mysql

Install :
sudo apt update  //mise à jour des packet
sudo apt install mysql-server

J'ai sécurisé mysql avec la commande mysql_secure_installation avant d'importer une base de donnée,mais une erreur a lieu et on doit pour éviter la boucle suivre ce shéma :
sudo mysql
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';
exit;

J'ai déja lancé la commande de sécurité et je me connecte après avec l'utilisateur
mysql -u root -p
ALTER USER 'root'@'localhost' IDENTIFIED WITH auth_socket;

Du coup il est créé et aussi le mot de passe pour l'utilisateur puis l'enleve pour permettre l'ajout de sécurité

Aprés j'ai crée un utilisateur pour mes bases de donnée puis je me connecte avec root
mysql -u root -p
Ensuite je crée et ajoute les droit à l'utilisateur
CREATE USER 'youness'@'localhost' IDENTIFIED WITH authentication_plugin BY 'booom';
GRANT ALL PRIVILEGES ON database.table TO 'youness'@'localhost';

Ainsi, pour l'importation d'une base de donnée :
Il faut télécharger le fichier depuis internet
On unzip le dossier :
cd ~/Downloads
unzip mysqlsampledatabase.zip

On se connecte à mysql et on déclare la nouvelle base de donnée:
mysql -u youness -p
source /home/youness/Downloads/mysqlsampledatabase.sql

Et finalement on affiche la base de donnée pour vérifier :
show databases;

======================================================================================================================


