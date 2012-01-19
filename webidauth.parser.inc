<?php

/**
 *     
 * @copyright 
 *     WebIDauth - WebID authentication module for Drupal
 *     Copyright (C) 2012  mEducator Best Practice Network
 * @license 
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.

 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.

 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * @author 
 *      Lazaros Ioannidis 
 *      Charalampos Bratsas
 *      Dimitris Spachos 
 * 
 */


class FoafParser
{
    /**
     * FoafParser::__construct()
     * Constructs a new instance of the FoafParser class
     * @param mixed $uri
     * @return
     */
    public function __construct($uri)
    {
        $this->graphite = new Graphite();
                $this->graphite->ns("cert", "http://www.w3.org/ns/auth/cert#");
                $this->graphite->ns("rsa", "http://www.w3.org/ns/auth/rsa#");
        $this->graphite->load($uri);
        $this->uri = $uri;
    }

    static private $graphite;
    private $uri;

    /**
     * FoafParser::getName()
     * Returns the name of the person described in the foaf profile
     * @return
     */
    public function getName()
    {
        return (string )$this->graphite->resource($this->uri)->get("foaf:nick");
    }

    /**
     * FoafParser::getImage()
     * Returns the image url of the person described in the foaf profile
     * @return
     */
    public function getImage()
    {
        return (string )$this->graphite->resource($this->uri)->get("foaf:img");
    }

    /**
     * FoafParser::getMailbox()
     * Returns the email address of the person described in the foaf profile
     * @return
     */
    public function getMailbox()
    {
        $prefix = 'mailto:';
        $mbox = (string )$this->graphite->resource($this->uri)->get("foaf:mbox");
        
        if ($mbox=='[NULL]') return '';

        if (substr($mbox, 0, strlen($prefix) ) == $prefix) {
            $mbox = substr($mbox, strlen($prefix), strlen($mbox) );        
        } 
        
        
        return $mbox ;
    }



}


?>