//Adapter design pattern is used when two incompatible interfaces need to work together
package Design_qsns.Design_patterns_java.Structural_design_pattern;
class Client {
    public void processData(Tool tool) {
        System.out.println("Processing data");
        tool.analyseData();
    }
}

class Tool {
    String data;
    Tool(String data) {
        this.data = data;
    }
    public void analyseData() {
        System.out.println("Analysing data: "+data);
    }
}

class XMLData {
    String data;
    XMLData(String data) {
        this.data = data;
    }

    public String toString() {
        return data;
    }
}

class AdapterTool extends Tool {
    XMLData xmlData;
    AdapterTool(XMLData xmlData) {
        super(xmlData.toString());
        this.xmlData = xmlData;
    }

    public void analyseData() {
        System.out.println("Analysing XML data:" + xmlData);
        super.analyseData();
    }
}


public class adapter_design_pattern {
    public static void main(String[] args) {
        Client client = new Client(); //Client is created
        XMLData xmlData = new XMLData("Sky is beautiful"); // XML data is created
        Tool tool = new AdapterTool(xmlData); // Adapter tool is created that takes on xml data and convert to json data and pass to tool which porcess that
        client.processData(tool); // client is provided with adapter tool to process data
    }
}
