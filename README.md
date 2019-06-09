# PSE-HTTP-SERVER-09

## Introduction
This repository contains a simple implementation of an http webserver,
together with its test, a doxygen documentation and a sample document root.


## Features
- Simple content serving from 3 different web roots (1 "protected" with basic authentication)
- Basic authentication with standard htpasswd file (SHA1 only)


## Installation
The makefile provides 2 ways of installing and running the server.
There is a manual way, and a full installation, which even populates the content folders.

No matter which way you prefer, you have to to the initial preparation and then continue with 
the manual or the automatic way. 

-------------------------------------------------------------

#### Preperation

 1. Install git and make
 	
 	Example for Debian/Ubuntu:
 	
 		sudo apt-get install git build-essential -y
 
 2. Install the needed libraries, if they are not already installed.
 
 	OpenSSL and the Magic library are needed.
 	
 	Example for Debian/Ubuntu:
 	
 		sudo apt-get install libmagic-dev	# Install Magic
 		sudo apt-get install libssl-dev		# Install OpenSSL
 
 3. Clone the git repository to a folder you like to run the program from.
 	
 	For this example we will assume that we clone to /home/user/documents
 	
 	Example if you have a valid ssh key added to GitLab:
 		
 		cd /home/user/documents
 		git clone ssh://git@git.fh-muenster.de:2323/lr413680/pse2019-gruppe09.git
 		
 	Example if you want to use http, in this case you will be asked for your GitLab credentials:
        
        cd /home/user/documents 	
    	git clone https://git@git.fh-muenster.de:2323/lr413680/pse2019-gruppe09.git
    	
 4. Now go into the newly created folder with the project in it by calling
   
   	    cd ./pse2019-gruppe09/
 
 Now we are ready to to the final installation by using **one** of the two ways.
 
 The [automatic version](#automatic-installation) is the preferred one because of convenience.
 
--------------------------------------------------------------

#### Automatic installation

If you install the program this way, the built executable will be copied to /usr/local/bin
by default and you can call it from anywhere. For this you need to be able to call sudo.

Also the standard webroot is copied to /usr/local/webroot so you wont have to do anything.

**IMPORTANT: For automatic installation it is required that all paths are default, 
otherwise the webroot wont't be found!**


 1. Build the executable by calling make (you have to still be in the folder where you ended preperation)

		make
		
 2. Call make install, to copy everything to the right place. For this you need to call it
 	with sudo or the current user has to have write right to /usr/local/.
 		
 		sudo make install
 
 3. At this point you should call make clean, even if it is not necessary
 
 		make clean
 
 4. Now the program is installed and can be called **system wide** by simply calling
 
 		http_server
 	
 	
 ---------------------------------------
 
 
 #### Manual installation
 
 1. Copy the [webroot](webroot) to the path specified in the [settings](#paths).
  	You can also create the folders yourself, and directly put your own website, htpasswd and status pages.
  	
  	Keep in mind that every path can be set to somewhere else, so simply copying the [webroot](webroot) 
  	may not work!
 
 2. Build the executable by calling make (you have to still be in the folder where you ended preperation)
 
 		make
 		
 3. In the folder you now find the executable called *http_server*. This file can be copied to anywhere
 	you want, but for now we will assume that you leve it where it is.
 	
 	Now if you are still in the folder where the file lies, you can start the server by calling:
 		
 		./http_server
 	
 	or if you are not in the folder where the file lies:
 	
 		/home/user/documents/pse2019-gruppe09/http_server
 		

 ----------------------
  
 *Note: If you want to serve your own websites, simply put them into the webroot folders for the different host,
 specified in the [settings](#paths)*.
 	
 
 	
## Settings

Settings have to be done before the build is done.
To change the settings, open [http_settings.h](include/http_settings.h) and edit it to your needs:


#### General

+ ##### SERVER_NAME
  The name of the server to be put into the HTTP responses.
  
  Default:
  
  	#define SERVER_NAME "HTTP-Server 09 1.0"
  	

+ ##### HTTP_VERSION
  The HTTP version to be send in the header.
  
  **Please only change if you know what you are doing,
  because the server is HTTP/1.1 so changing this could make it incompatible to any browser!**
  
  Default:
  
  	#define HTTP_VERSION "HTTP/1.1"
  	
  	
  	
#### General
  	
+ ##### PORT
  The tcp port, the server listens on for requests.
  For usage of http standard port 80,
  the program has to be run as superuser so it is not used by default.
  
  Default:
  
  	#define PORT 31337


+ ##### BUFFER_SIZE
  The size of the buffer, used for reading messages from the tcp connection.
  Choose an appropriate size, if it is to small, longer messages can not be responded to.
  But keep in mind that the memory has to be allocated, so it also can not be infinitely huge.
  
  The value has to be given in bytes.
  
  Default:
  
  	#define PORT 31337
  	
  	
  	
#### Paths

+ ##### DEFAULT_DOCUMENT_ROOT
  This is the path where all files that should be served when no special host is 
  requested or the host is unknown lie. 
  
  Default:
  
  	#define DEFAULT_DOCUMENT_ROOT "/usr/local/webroot/default/"
  	

+ ##### EXTERN_DOCUMENT_ROOT
  This is the path where all files that should be served when the host "extern"
  is requested lie. 
  
  Default:
  
  	#define EXTERN_DOCUMENT_ROOT "/usr/local/webroot/extern/"
  	
  	
+ ##### INTERN_DOCUMENT_ROOT
  This is the path where all files that should be served when the host "intern"
  is requested lie. Keep in mind that this document root, is "protected" via basic
  authentication. The credentials lie in the htpasswd file.
      
  Default:
  	
  	#define INTERN_DOCUMENT_ROOT "/usr/local/webroot/intern/"
      
      
+ ##### STATUS_SITE_PATH
  This path contains all status pages. Each status page is named after its status.
  Each status has its own site, and any html file with a fitting name can be used.
  
  For example a page for status 505 is named: "505.html"
      
  Default:
  
  	#define STATUS_SITE_PATH "/usr/local/webroot/status/"
      
      
+ ##### HTPASSWD_PATH
  This path contains the htpasswd file.
  The server only supports SHA1 encrypted credentials, so keep in mind to set the -s 
  flag wen creating credentials with htpasswd.
  
  This file can be created by the command:
  
  	htpasswd -s -c htpasswd [username]
  	
  Using this command, the htpasswd file will be created or updated, the user [username]
  will be created and you will be promted to type in a password for the new user.
  
  Default:
  	
  	#define HTPASSWD_PATH "/usr/local/webroot/htpasswd"