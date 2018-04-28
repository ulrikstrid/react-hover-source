type prismLanguage;

[@bs.module "prismjs"]
external highlight : (string, prismLanguage) => string = "highlight";

[@bs.module "prismjs"] [@bs.scope "languages"]
external html : prismLanguage = "html";
