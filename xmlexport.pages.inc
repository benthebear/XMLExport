<?php

function xmlexport_show_xml(){

	if ($node = node_load(arg(1))) {
		$result = db_query('SELECT * FROM {comments} WHERE nid = %d', $node->nid);
		while ($comment = db_fetch_array($result)){
			$node->comments[] = $comment;
		}

		drupal_set_header('Content-Type: application/xml; charset=utf-8');

		//print "<pre>".print_r($node)."</pre>";
		$output = xmlexport_node2xml($node);
		print $output;
		die();
	}

	else {
		drupal_not_found();
	}
}

function xmlexport_show_admin(){

	if ($node = node_load(arg(2))) {
		$result = db_query('SELECT * FROM {comments} WHERE nid = %d', $node->nid);
		while ($comment = db_fetch_array($result)){
			$node->comments[] = $comment;
		}

		//drupal_set_header('Content-Type: application/xml; charset=utf-8');

		//print "<pre>".print_r($node)."</pre>";
		$file = fopen("tests/myxml.txt", "a+");
		$output = xmlexport_node2xml($node);
		fwrite($file, $output);
		fclose($file);
		
	}
	
	$next = arg(2)+1;
		$text .= "<p>goto Post ".$next."</p>";
		if($next<=7500){
			$text .= "<p>Skript</p><script type='text/javascript'>setTimeout('', 5000);window.location='http://anmutunddemut.de/admin/xmlexport/".$next."';</script>";
		}
		print $text;
		die();


	//drupal_goto("admin/xmlexport/".(arg(2)+1));

}

