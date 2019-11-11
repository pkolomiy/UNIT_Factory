package com.avaj;

import java.io.Reader;
import java.io.StringReader;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import javax.swing.text.MutableAttributeSet;
import javax.swing.text.html.HTML.Tag;
import javax.swing.text.html.HTML.Attribute;
import javax.swing.text.html.HTMLEditorKit.ParserCallback;
import javax.swing.text.html.parser.ParserDelegator;
import java.util.ArrayList;

public class Md5Decode {
    static String decode(String hash) throws Exception {
        Reader reader = new StringReader(HttpClient.newHttpClient().send(HttpRequest.newBuilder().uri(URI.create("https://md5.gromweb.com/?md5=" + hash)).build(), HttpResponse.BodyHandlers.ofString()).body());
        HTMLParser callback = new HTMLParser();
        new ParserDelegator().parse(reader, callback, true);
        reader.close();
        String message = callback.data.get(0);
        if (message.contains("errors") || message.contains("no reverse string was found")) {
            return null;
        }
        return callback.data.get(3);
    }
}

class HTMLParser extends ParserCallback {

    private boolean insideTag = false;
    ArrayList<String> data = new ArrayList<>();

    public void handleText(char[] data, int pos) {
        if (insideTag) {
            this.data.add(new String(data));
        }
    }

    public void handleStartTag(Tag t, MutableAttributeSet a, int pos) {
        if (t == Tag.DIV && a.containsAttribute(Attribute.ID, "content")) {
            insideTag = true;
        }
    }

    public void handleEndTag(Tag t, int pos) {
        if (t == Tag.DIV) {
            insideTag = false;
        }
    }
}
