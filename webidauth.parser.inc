<?php
if (module_exists('libraries')) {
    define('RDF_ARC2_PATH', libraries_get_path('ARC2') . '/arc');
    define('GRAPHITE_RDF_PATH',libraries_get_path('Graphite'))       ;
} else {
    define('RDF_ARC2_PATH', drupal_get_path('module', 'webidauth') . '/vendor/arc');
}
  if (!class_exists('ARC2')) {
    @include_once RDF_ARC2_PATH . '/ARC2.php';
    @include_once GRAPHITE_RDF_PATH . '/Graphite.php';
  }

/**
 * @author Larry
 * @copyright 2011
 */
class FoafParser
{
    public function __construct($uri)
    {
        $this->graphite = new Graphite();
                $this->graphite->ns("cert", "http://www.w3.org/ns/auth/cert#");

        $this->graphite->load($uri);
        $this->uri = $uri;
    }

    static private $graphite;
    private $uri;

    public function getName()
    {
        return (string )$this->graphite->resource($this->uri)->get("foaf:name");
    }

    public function getImage()
    {
        return (string )$this->graphite->resource($this->uri)->get("foaf:img");
    }

    public function getMailbox()
    {
        return (string )$this->graphite->resource($this->uri)->get("foaf:mbox");
    }

    public function getCertificateModulus()
    {
        //$this->graphite->ns("cert", "http://www.w3.org/ns/auth/cert#");
        
        foreach ($this->graphite->allOfType('cert:RSAPublicKey') as $certs) {
            $hex[] = $certs->get('cert:modulus');
     
            
            }
        
        return trim($hex[0]);

    }
    
    public function getCertificates(){
        foreach ($this->graphite->allOfType('cert:RSAPublicKey') as $certs) {
            $hex[] = $certs->get('cert:modulus');
     
            
            }
        return $hex;
        
    }


}


?>