#include "ECMrest.h"
#include "jsonutil.h"

RateModel ECMrestModel() {
  RateModel m;
  ParsedJson pj (ECMrestModelText);
  m.read (pj.value);
  return m;
}

const char* ECMrestModelText =
"{\n"
"  \"insrate\": 0.01,\n"
"  \"delrate\": 0.01,\n"
"  \"insextprob\": 0.66,\n"
"  \"delextprob\": 0.66,\n"
"  \"alphabet\": \"FfLlSs5$YyCcW<[{/Pp,8HhQqRr=}Ii|MTt~`NnKk%#3]Vv^7Aa4&DdEeGg96\",\n"
"  \"rootprob\": {\n"
"    \"3\": 0.010372,\n"
"    \"4\": 0.015908,\n"
"    \"5\": 0.00975,\n"
"    \"6\": 0.010191,\n"
"    \"7\": 0.022747,\n"
"    \"8\": 0.011843,\n"
"    \"9\": 0.015796,\n"
"    \"F\": 0.022103,\n"
"    \"f\": 0.021383,\n"
"    \"L\": 0.016387,\n"
"    \"l\": 0.015425,\n"
"    \"S\": 0.01188,\n"
"    \"s\": 0.011131,\n"
"    \"$\": 0.008956,\n"
"    \"Y\": 0.015965,\n"
"    \"y\": 0.015782,\n"
"    \"C\": 0.006025,\n"
"    \"c\": 0.007029,\n"
"    \"W\": 0.01188,\n"
"    \"<\": 0.014467,\n"
"    \"[\": 0.017386,\n"
"    \"{\": 0.0076,\n"
"    \"/\": 0.028839,\n"
"    \"P\": 0.010007,\n"
"    \"p\": 0.0101,\n"
"    \",\": 0.010642,\n"
"    \"H\": 0.011097,\n"
"    \"h\": 0.011703,\n"
"    \"Q\": 0.016076,\n"
"    \"q\": 0.020211,\n"
"    \"R\": 0.008311,\n"
"    \"r\": 0.014148,\n"
"    \"=\": 0.0048,\n"
"    \"}\": 0.007837,\n"
"    \"I\": 0.025576,\n"
"    \"i\": 0.023441,\n"
"    \"|\": 0.013551,\n"
"    \"M\": 0.020102,\n"
"    \"T\": 0.013424,\n"
"    \"t\": 0.020201,\n"
"    \"~\": 0.015528,\n"
"    \"`\": 0.012142,\n"
"    \"N\": 0.023006,\n"
"    \"n\": 0.020171,\n"
"    \"K\": 0.030001,\n"
"    \"k\": 0.026344,\n"
"    \"%\": 0.010142,\n"
"    \"#\": 0.011679,\n"
"    \"]\": 0.008195,\n"
"    \"V\": 0.019047,\n"
"    \"v\": 0.018938,\n"
"    \"^\": 0.010901,\n"
"    \"A\": 0.019005,\n"
"    \"a\": 0.028307,\n"
"    \"&\": 0.018853,\n"
"    \"D\": 0.028198,\n"
"    \"d\": 0.024532,\n"
"    \"E\": 0.033223,\n"
"    \"e\": 0.031878,\n"
"    \"G\": 0.016852,\n"
"    \"g\": 0.022982\n"
"  },\n"
"  \"subrate\": {\n"
"    \"3\": {\n"
"      \"9\": 0.02262634836,\n"
"      \"=\": 0.4433867423999999,\n"
"      \"|\": 0.025789924425000003,\n"
"      \"~\": 0.011708966040000001,\n"
"      \"K\": 0.252721283762,\n"
"      \"%\": 0.01817694879,\n"
"      \"#\": 0.0014119910999999998,\n"
"      \"]\": 0.2974187174749999\n"
"    },\n"
"    \"4\": {\n"
"      \"5\": 0.09633372450000001,\n"
"      \"9\": 0.047152529028000004,\n"
"      \",\": 0.031116910024,\n"
"      \"~\": 0.047578863432,\n"
"      \"^\": 0.068579804348,\n"
"      \"A\": 0.41640382612500004,\n"
"      \"a\": 0.144094603861,\n"
"      \"&\": 0.179652895273,\n"
"      \"E\": 0.092175386235\n"
"    },\n"
"    \"5\": {\n"
"      \"4\": 0.157177116856,\n"
"      \"L\": 0.048379864484,\n"
"      \"S\": 0.5275665054,\n"
"      \"s\": 0.152291570381,\n"
"      \"$\": 0.116355107116,\n"
"      \",\": 0.035254934662,\n"
"      \"~\": 0.093694896096\n"
"    },\n"
"    \"6\": {\n"
"      \"7\": 0.006880990247,\n"
"      \"9\": 0.30145514471600005,\n"
"      \"W\": 0.00963296928,\n"
"      \"}\": 0.037646894706,\n"
"      \"]\": 0.04415887222999999,\n"
"      \"&\": 0.125277638263,\n"
"      \"e\": 0.04443187518,\n"
"      \"G\": 0.223237365472,\n"
"      \"g\": 0.415165831132\n"
"    },\n"
"    \"7\": {\n"
"      \"6\": 0.0030827876910000003,\n"
"      \"l\": 0.031190907925,\n"
"      \"/\": 0.062430811394999994,\n"
"      \"M\": 0.041780881288,\n"
"      \"V\": 0.169540527849,\n"
"      \"v\": 0.410152840832,\n"
"      \"^\": 0.129701635041,\n"
"      \"&\": 0.11625804256200001,\n"
"      \"e\": 0.015177275189999999\n"
"    },\n"
"    \"8\": {\n"
"      \"$\": 0.01167396688,\n"
"      \"/\": 0.013773967824,\n"
"      \"P\": 0.08412975963699999,\n"
"      \"p\": 0.2884351839,\n"
"      \",\": 0.120203656746,\n"
"      \"q\": 0.036266375868,\n"
"      \"}\": 0.024641847752000002,\n"
"      \"`\": 0.0150372599,\n"
"      \"&\": 0.11377514016800001\n"
"    },\n"
"    \"9\": {\n"
"      \"3\": 0.014856956519999999,\n"
"      \"4\": 0.047486859443999996,\n"
"      \"6\": 0.19448780576100003,\n"
"      \"=\": 0.00043699679999999994,\n"
"      \"^\": 0.007656982311,\n"
"      \"E\": 0.029036902000000003,\n"
"      \"G\": 0.3457710212,\n"
"      \"g\": 0.094707741846\n"
"    },\n"
"    \"F\": {\n"
"      \"f\": 0.23931904919199998,\n"
"      \"L\": 0.021558901069999997,\n"
"      \"l\": 0.08371264729999998,\n"
"      \"S\": 0.01969764588,\n"
"      \"Y\": 0.10554292271,\n"
"      \"C\": 0.0201678681,\n"
"      \"<\": 0.030246894717,\n"
"      \"I\": 0.043019573704,\n"
"      \"V\": 0.043080752211\n"
"    },\n"
"    \"f\": {\n"
"      \"F\": 0.247377306472,\n"
"      \"L\": 0.00017855275199999998,\n"
"      \"l\": 0.07336574239999999,\n"
"      \"s\": 0.021299958801,\n"
"      \"y\": 0.08171809126,\n"
"      \"c\": 0.010954858167,\n"
"      \"[\": 0.039403160978,\n"
"      \"i\": 0.018425633963,\n"
"      \"v\": 0.036425197696\n"
"    },\n"
"    \"L\": {\n"
"      \"5\": 0.028785237,\n"
"      \"F\": 0.02907892783,\n"
"      \"f\": 0.00023298916799999997,\n"
"      \"l\": 0.381749545875,\n"
"      \"{\": 0.5757200488,\n"
"      \"|\": 0.137089883988,\n"
"      \"^\": 0.025756010719999996\n"
"    },\n"
"    \"l\": {\n"
"      \"7\": 0.045996731447000005,\n"
"      \"F\": 0.11995466082799999,\n"
"      \"f\": 0.10170370630399998,\n"
"      \"L\": 0.40555784818499996,\n"
"      \"$\": 0.072784641784,\n"
"      \"W\": 0.06379137072,\n"
"      \"/\": 0.602078089902,\n"
"      \"M\": 0.159028851792\n"
"    },\n"
"    \"S\": {\n"
"      \"5\": 0.43297756125000003,\n"
"      \"F\": 0.036647901253,\n"
"      \"s\": 0.154599594362,\n"
"      \"$\": 0.152766459508,\n"
"      \"Y\": 0.03521965211,\n"
"      \"C\": 0.037303673025,\n"
"      \"P\": 0.017705935485,\n"
"      \"T\": 0.5131874384,\n"
"      \"A\": 0.10528868826000001\n"
"    },\n"
"    \"s\": {\n"
"      \"5\": 0.13339707225,\n"
"      \"f\": 0.040917888693,\n"
"      \"S\": 0.16500253176,\n"
"      \"$\": 0.583008920076,\n"
"      \"y\": 0.088623379104,\n"
"      \"c\": 0.06564527897400001,\n"
"      \"p\": 0.027316470099999997,\n"
"      \"t\": 0.319046412595,\n"
"      \"a\": 0.21727994626599997\n"
"    },\n"
"    \"$\": {\n"
"      \"5\": 0.12667064475,\n"
"      \"8\": 0.015437113639999998,\n"
"      \"l\": 0.12535764845,\n"
"      \"S\": 0.20264242284,\n"
"      \"s\": 0.724594940751,\n"
"      \"W\": 0.05538457188,\n"
"      \"`\": 0.207675602368,\n"
"      \"&\": 0.412186117774\n"
"    },\n"
"    \"Y\": {\n"
"      \"F\": 0.146120590082,\n"
"      \"S\": 0.02620792152,\n"
"      \"y\": 0.314737553676,\n"
"      \"C\": 0.0035070561,\n"
"      \"H\": 0.038228765508,\n"
"      \"N\": 0.05165778743,\n"
"      \"D\": 0.010364259494000001\n"
"    },\n"
"    \"y\": {\n"
"      \"f\": 0.11071967718999999,\n"
"      \"s\": 0.062505818832,\n"
"      \"Y\": 0.31838708937,\n"
"      \"c\": 0.0010141300619999998,\n"
"      \"h\": 0.082948535103,\n"
"      \"n\": 0.004606269731000001,\n"
"      \"d\": 0.007229629464000001\n"
"    },\n"
"    \"C\": {\n"
"      \"F\": 0.073986786492,\n"
"      \"S\": 0.07355479427999999,\n"
"      \"Y\": 0.00929297106,\n"
"      \"c\": 0.314744308956,\n"
"      \"W\": 0.00804486276,\n"
"      \"R\": 0.013439643301000002,\n"
"      \"%\": 0.047865057438,\n"
"      \"G\": 0.018616859404\n"
"    },\n"
"    \"c\": {\n"
"      \"f\": 0.033325897309,\n"
"      \"s\": 0.10395470198600001,\n"
"      \"y\": 0.002276995396,\n"
"      \"C\": 0.26978723309999997,\n"
"      \"W\": 0.00087042384,\n"
"      \"r\": 0.023102905860000002,\n"
"      \"#\": 0.023914551066,\n"
"      \"g\": 0.012705621681999998\n"
"    },\n"
"    \"W\": {\n"
"      \"6\": 0.008263433496,\n"
"      \"l\": 0.0828267587,\n"
"      \"$\": 0.041752880956,\n"
"      \"C\": 0.004079991425,\n"
"      \"c\": 0.000515000772,\n"
"      \"}\": 0.023715435982,\n"
"      \"]\": 0.006761546989999999\n"
"    },\n"
"    \"<\": {\n"
"      \"F\": 0.046211869353,\n"
"      \"[\": 0.15483074482399997,\n"
"      \"{\": 0.4317094576,\n"
"      \"/\": 0.243180224421,\n"
"      \"P\": 0.012647226866,\n"
"      \"H\": 0.017567838252,\n"
"      \"R\": 0.006478964715,\n"
"      \"I\": 0.1100081306,\n"
"      \"V\": 0.047115097281\n"
"    },\n"
"    \"[\": {\n"
"      \"f\": 0.048461853859,\n"
"      \"<\": 0.128835637028,\n"
"      \"{\": 0.059365158,\n"
"      \"/\": 0.636723707196,\n"
"      \"p\": 0.0140363235,\n"
"      \"h\": 0.037809478953,\n"
"      \"r\": 0.03184389396,\n"
"      \"i\": 0.149596734881,\n"
"      \"v\": 0.11201773973599999\n"
"    },\n"
"    \"{\": {\n"
"      \"L\": 1.241358478906,\n"
"      \"<\": 0.8217816740920001,\n"
"      \"[\": 0.13580561013,\n"
"      \"/\": 0.162943695324,\n"
"      \",\": 0.014831542560000001,\n"
"      \"Q\": 0.119268776408,\n"
"      \"=\": 0.014514907199999998,\n"
"      \"|\": 0.069577053909,\n"
"      \"^\": 0.040742367588999996\n"
"    },\n"
"    \"/\": {\n"
"      \"7\": 0.049242819335,\n"
"      \"8\": 0.005656406288,\n"
"      \"l\": 0.32203108765,\n"
"      \"<\": 0.12199064831300002,\n"
"      \"[\": 0.38385791370399996,\n"
"      \"{\": 0.042940881599999994,\n"
"      \"q\": 0.03663324594,\n"
"      \"}\": 0.011465099965,\n"
"      \"M\": 0.051664612546\n"
"    },\n"
"    \"P\": {\n"
"      \"8\": 0.09956517871299998,\n"
"      \"S\": 0.0210199374,\n"
"      \"<\": 0.018283944346000003,\n"
"      \"p\": 0.1763624327,\n"
"      \",\": 0.37758840824600004,\n"
"      \"H\": 0.011337605153999999,\n"
"      \"R\": 0.0027772453150000003,\n"
"      \"T\": 0.088316173824,\n"
"      \"A\": 0.022030310925\n"
"    },\n"
"    \"p\": {\n"
"      \"8\": 0.338211671577,\n"
"      \"s\": 0.030104913730999997,\n"
"      \"[\": 0.024161932709999997,\n"
"      \"P\": 0.17473850138900002,\n"
"      \",\": 0.128276826934,\n"
"      \"h\": 0.044173488432,\n"
"      \"r\": 0.024041724696,\n"
"      \"t\": 0.02897934455,\n"
"      \"a\": 0.08832319002299999\n"
"    },\n"
"    \",\": {\n"
"      \"4\": 0.046514546575999995,\n"
"      \"5\": 0.03229990725,\n"
"      \"8\": 0.133769207559,\n"
"      \"{\": 0.010591968,\n"
"      \"P\": 0.355057996741,\n"
"      \"p\": 0.1217436527,\n"
"      \"Q\": 0.086518909968,\n"
"      \"=\": 0.0081295776,\n"
"      \"~\": 0.014372328600000001\n"
"    },\n"
"    \"H\": {\n"
"      \"Y\": 0.05499885026,\n"
"      \"<\": 0.022902939172,\n"
"      \"P\": 0.010223971774,\n"
"      \"h\": 0.32869233048,\n"
"      \"Q\": 0.05530754888,\n"
"      \"q\": 0.021955754997,\n"
"      \"R\": 0.025096942786000002,\n"
"      \"N\": 0.11513955457200001,\n"
"      \"D\": 0.010819741788\n"
"    },\n"
"    \"h\": {\n"
"      \"y\": 0.111859675382,\n"
"      \"[\": 0.056169836885999996,\n"
"      \"p\": 0.0381228944,\n"
"      \"H\": 0.31167211751999996,\n"
"      \"Q\": 0.030848300704,\n"
"      \"q\": 0.108522216693,\n"
"      \"r\": 0.09927508705200001,\n"
"      \"n\": 0.08281409794200001,\n"
"      \"d\": 0.073763479964\n"
"    },\n"
"    \"Q\": {\n"
"      \"{\": 0.056384840799999995,\n"
"      \",\": 0.057273839256,\n"
"      \"H\": 0.03817789686,\n"
"      \"h\": 0.022456933512,\n"
"      \"q\": 0.30233940086100003,\n"
"      \"=\": 0.030795633599999997,\n"
"      \"K\": 0.19213948443599999,\n"
"      \"E\": 0.14901741428700002\n"
"    },\n"
"    \"q\": {\n"
"      \"8\": 0.021250937084,\n"
"      \"/\": 0.052271841060000004,\n"
"      \"H\": 0.012054970719,\n"
"      \"h\": 0.062838825489,\n"
"      \"Q\": 0.240483311476,\n"
"      \"}\": 0.156120696749,\n"
"      \"k\": 0.071542190048,\n"
"      \"e\": 0.24503923659599997\n"
"    },\n"
"    \"R\": {\n"
"      \"C\": 0.009742973275,\n"
"      \"<\": 0.011277966855,\n"
"      \"P\": 0.003343989155,\n"
"      \"H\": 0.03350989942199999,\n"
"      \"r\": 0.206615368836,\n"
"      \"=\": 0.47740776479999997,\n"
"      \"}\": 0.24141682575,\n"
"      \"%\": 0.038891182572,\n"
"      \"G\": 0.0006934598\n"
"    },\n"
"    \"r\": {\n"
"      \"c\": 0.011477970405,\n"
"      \"[\": 0.03913188722,\n"
"      \"p\": 0.0171629502,\n"
"      \"h\": 0.082118768997,\n"
"      \"R\": 0.12137265552700001,\n"
"      \"=\": 0.0716652768,\n"
"      \"}\": 0.62291399201,\n"
"      \"#\": 0.058787764769999994,\n"
"      \"g\": 0.02878426554\n"
"    },\n"
"    \"=\": {\n"
"      \"3\": 0.9580848525359998,\n"
"      \"9\": 0.001438083636,\n"
"      \"{\": 0.0229819364,\n"
"      \",\": 0.018023951004,\n"
"      \"Q\": 0.103139709532,\n"
"      \"R\": 0.8266116527610001,\n"
"      \"r\": 0.211233403368,\n"
"      \"}\": 0.10908909642400001\n"
"    },\n"
"    \"}\": {\n"
"      \"6\": 0.048954893958000005,\n"
"      \"8\": 0.037237897528000004,\n"
"      \"W\": 0.03594990168,\n"
"      \"/\": 0.042189870855,\n"
"      \"q\": 0.402622866147,\n"
"      \"R\": 0.25601827725,\n"
"      \"r\": 1.12453581204,\n"
"      \"=\": 0.0668148096,\n"
"      \"]\": 1.0923631047449998\n"
"    },\n"
"    \"I\": {\n"
"      \"F\": 0.037177886987,\n"
"      \"<\": 0.062225822075,\n"
"      \"i\": 0.237708805048,\n"
"      \"|\": 0.2479683939,\n"
"      \"M\": 0.025766421967999997,\n"
"      \"T\": 0.037608195136,\n"
"      \"N\": 0.011527248323999999,\n"
"      \"%\": 0.0058632727560000006,\n"
"      \"V\": 0.13516286420700002\n"
"    },\n"
"    \"i\": {\n"
"      \"f\": 0.016807957469,\n"
"      \"[\": 0.11095468762599998,\n"
"      \"I\": 0.259359259328,\n"
"      \"|\": 0.062658956736,\n"
"      \"M\": 0.026212023002,\n"
"      \"t\": 0.045077885068,\n"
"      \"n\": 0.005903870161,\n"
"      \"#\": 0.005112820941,\n"
"      \"v\": 0.191980888106\n"
"    },\n"
"    \"|\": {\n"
"      \"3\": 0.019739731099999998,\n"
"      \"L\": 0.16578052755599998,\n"
"      \"{\": 0.039021888399999996,\n"
"      \"I\": 0.4680126664,\n"
"      \"i\": 0.10838968377599999,\n"
"      \"M\": 0.041854937056,\n"
"      \"~\": 0.0770553708,\n"
"      \"K\": 0.07943124761999999,\n"
"      \"^\": 0.275733142498\n"
"    },\n"
"    \"M\": {\n"
"      \"7\": 0.047278365668000005,\n"
"      \"l\": 0.1220286558,\n"
"      \"/\": 0.07411977719700001,\n"
"      \"I\": 0.032782907584,\n"
"      \"i\": 0.030565915391000002,\n"
"      \"|\": 0.028214916528,\n"
"      \"`\": 0.09902147047,\n"
"      \"k\": 0.025687349456,\n"
"      \"]\": 0.018288470089999998\n"
"    },\n"
"    \"T\": {\n"
"      \"S\": 0.45416170800000005,\n"
"      \"P\": 0.065835812832,\n"
"      \"I\": 0.071652800864,\n"
"      \"t\": 0.12192798374,\n"
"      \"~\": 0.439564698528,\n"
"      \"`\": 0.237727999444,\n"
"      \"N\": 0.269526240856,\n"
"      \"%\": 0.399587923724,\n"
"      \"A\": 0.09707048914500001\n"
"    },\n"
"    \"t\": {\n"
"      \"s\": 0.175798505945,\n"
"      \"p\": 0.014488955,\n"
"      \"i\": 0.052307841388,\n"
"      \"T\": 0.08102377376,\n"
"      \"~\": 0.10819374684,\n"
"      \"`\": 0.466434553598,\n"
"      \"n\": 0.04305984054,\n"
"      \"#\": 0.249205836297,\n"
"      \"a\": 0.06545300228499999\n"
"    },\n"
"    \"~\": {\n"
"      \"3\": 0.00782105846,\n"
"      \"4\": 0.04874320965199999,\n"
"      \"5\": 0.058830837000000004,\n"
"      \",\": 0.00984996915,\n"
"      \"|\": 0.06724480485,\n"
"      \"T\": 0.380004927424,\n"
"      \"t\": 0.140753598655,\n"
"      \"`\": 0.153946013884,\n"
"      \"K\": 0.11758471936\n"
"    },\n"
"    \"`\": {\n"
"      \"8\": 0.01466696335,\n"
"      \"$\": 0.153182564224,\n"
"      \"M\": 0.16393753906999997,\n"
"      \"T\": 0.262828254368,\n"
"      \"t\": 0.776020788769,\n"
"      \"~\": 0.196876437456,\n"
"      \"k\": 0.15463551280799998,\n"
"      \"]\": 0.18502073584499998,\n"
"      \"&\": 0.4800265832970001\n"
"    },\n"
"    \"N\": {\n"
"      \"Y\": 0.035847890825,\n"
"      \"H\": 0.055537843914,\n"
"      \"I\": 0.012814957104000001,\n"
"      \"T\": 0.15726854982400001,\n"
"      \"n\": 0.279643643808,\n"
"      \"K\": 0.147889419483,\n"
"      \"k\": 0.026613024928000002,\n"
"      \"%\": 0.168595831118,\n"
"      \"D\": 0.171772459492\n"
"    },\n"
"    \"n\": {\n"
"      \"y\": 0.0036039933020000003,\n"
"      \"h\": 0.048047860206,\n"
"      \"i\": 0.006860969731,\n"
"      \"t\": 0.04312388274,\n"
"      \"N\": 0.31894708588799997,\n"
"      \"K\": 0.010988376267,\n"
"      \"k\": 0.025893333192,\n"
"      \"#\": 0.090918305472,\n"
"      \"d\": 0.09042676736800001\n"
"    },\n"
"    \"K\": {\n"
"      \"3\": 0.087371259464,\n"
"      \"Q\": 0.102957713136,\n"
"      \"|\": 0.03587789862,\n"
"      \"~\": 0.06085982208,\n"
"      \"N\": 0.113407685898,\n"
"      \"n\": 0.0073879716570000005,\n"
"      \"k\": 0.283537231688,\n"
"      \"E\": 0.093403075754\n"
"    },\n"
"    \"k\": {\n"
"      \"q\": 0.054886851012000006,\n"
"      \"M\": 0.019600937548,\n"
"      \"`\": 0.07127180369399999,\n"
"      \"N\": 0.023240937272000002,\n"
"      \"n\": 0.019825934703000002,\n"
"      \"K\": 0.322897072877,\n"
"      \"]\": 0.17209793380999996,\n"
"      \"e\": 0.06664545379799999\n"
"    },\n"
"    \"%\": {\n"
"      \"3\": 0.01858916514,\n"
"      \"C\": 0.028434921225000003,\n"
"      \"R\": 0.031869909126000004,\n"
"      \"I\": 0.014785945968000001,\n"
"      \"T\": 0.528896498528,\n"
"      \"N\": 0.382440908174,\n"
"      \"#\": 0.311101324572,\n"
"      \"]\": 0.027244941294999995,\n"
"      \"G\": 0.17847582456\n"
"    },\n"
"    \"#\": {\n"
"      \"3\": 0.0012539747999999998,\n"
"      \"c\": 0.014392959965999999,\n"
"      \"r\": 0.07121579724,\n"
"      \"i\": 0.010261977539,\n"
"      \"t\": 0.43104778654299997,\n"
"      \"n\": 0.157026555328,\n"
"      \"%\": 0.270159228856,\n"
"      \"]\": 0.04926809414999999,\n"
"      \"g\": 0.09849034922599999\n"
"    },\n"
"    \"]\": {\n"
"      \"3\": 0.37642793625999993,\n"
"      \"6\": 0.054914346174,\n"
"      \"W\": 0.009801974159999999,\n"
"      \"}\": 1.044643032567,\n"
"      \"M\": 0.044860869523999994,\n"
"      \"`\": 0.274133224482,\n"
"      \"k\": 0.553233431152,\n"
"      \"%\": 0.033717900502,\n"
"      \"#\": 0.07021379763\n"
"    },\n"
"    \"V\": {\n"
"      \"7\": 0.202474845749,\n"
"      \"F\": 0.049992852739000004,\n"
"      \"<\": 0.035785903941,\n"
"      \"I\": 0.181494482856,\n"
"      \"v\": 0.12631560779,\n"
"      \"^\": 0.283917395278,\n"
"      \"A\": 0.06997815846000001,\n"
"      \"D\": 0.00995149717,\n"
"      \"G\": 0.008483044019999999\n"
"    },\n"
"    \"v\": {\n"
"      \"7\": 0.492646883008,\n"
"      \"f\": 0.041127891135999996,\n"
"      \"[\": 0.10283770319199999,\n"
"      \"i\": 0.237629316617,\n"
"      \"V\": 0.127042632885,\n"
"      \"^\": 0.038496456361,\n"
"      \"a\": 0.121958303405,\n"
"      \"d\": 0.005115461704000001,\n"
"      \"g\": 0.012472722093999999\n"
"    },\n"
"    \"^\": {\n"
"      \"4\": 0.10007958238399998,\n"
"      \"7\": 0.27064701332700003,\n"
"      \"9\": 0.011095284156000002,\n"
"      \"L\": 0.038717892639999994,\n"
"      \"{\": 0.0284049164,\n"
"      \"|\": 0.34276303219800003,\n"
"      \"V\": 0.496080600666,\n"
"      \"v\": 0.06687880841800001,\n"
"      \"E\": 0.042454376003\n"
"    },\n"
"    \"A\": {\n"
"      \"4\": 0.3485478593,\n"
"      \"S\": 0.06581581776,\n"
"      \"P\": 0.011599964295,\n"
"      \"T\": 0.068564811696,\n"
"      \"V\": 0.070132806324,\n"
"      \"a\": 0.184457441933,\n"
"      \"&\": 0.103928783858,\n"
"      \"D\": 0.019541947148,\n"
"      \"G\": 0.025975318908\n"
"    },\n"
"    \"a\": {\n"
"      \"4\": 0.080978449084,\n"
"      \"s\": 0.085439752778,\n"
"      \"p\": 0.0315139089,\n"
"      \"t\": 0.046709863255,\n"
"      \"v\": 0.08159276327000001,\n"
"      \"A\": 0.12384264259500001,\n"
"      \"&\": 0.39054643699100006,\n"
"      \"d\": 0.04579057258,\n"
"      \"g\": 0.052938738234\n"
"    },\n"
"    \"&\": {\n"
"      \"4\": 0.15158957502799997,\n"
"      \"6\": 0.067718899461,\n"
"      \"7\": 0.140270603838,\n"
"      \"8\": 0.071470799608,\n"
"      \"$\": 0.195806443048,\n"
"      \"`\": 0.309154127958,\n"
"      \"A\": 0.10476669693,\n"
"      \"a\": 0.586389327529,\n"
"      \"e\": 0.30098949388199997\n"
"    },\n"
"    \"D\": {\n"
"      \"Y\": 0.005867983645000001,\n"
"      \"H\": 0.0042579854819999995,\n"
"      \"N\": 0.140144591924,\n"
"      \"V\": 0.006721972005,\n"
"      \"A\": 0.013170959130000002,\n"
"      \"d\": 0.260183914268,\n"
"      \"E\": 0.09005459603,\n"
"      \"e\": 0.041323260131999995,\n"
"      \"G\": 0.017570299648\n"
"    },\n"
"    \"d\": {\n"
"      \"y\": 0.004650986964000001,\n"
"      \"h\": 0.035188896381,\n"
"      \"n\": 0.074351798654,\n"
"      \"v\": 0.003948989636,\n"
"      \"a\": 0.052836855455,\n"
"      \"D\": 0.299065140002,\n"
"      \"E\": 0.021597873624,\n"
"      \"e\": 0.12046865153399999,\n"
"      \"g\": 0.035889357678\n"
"    },\n"
"    \"E\": {\n"
"      \"4\": 0.04413587106,\n"
"      \"9\": 0.013805704,\n"
"      \"Q\": 0.072106792044,\n"
"      \"K\": 0.084344751398,\n"
"      \"^\": 0.013929962760999998,\n"
"      \"D\": 0.07643378078,\n"
"      \"d\": 0.015947958816000002,\n"
"      \"e\": 0.32367550446\n"
"    },\n"
"    \"e\": {\n"
"      \"6\": 0.01420431771,\n"
"      \"7\": 0.010829960435,\n"
"      \"q\": 0.155357551002,\n"
"      \"k\": 0.055075846504000006,\n"
"      \"&\": 0.17800849890700002,\n"
"      \"D\": 0.036552898212,\n"
"      \"d\": 0.09270772819600001,\n"
"      \"E\": 0.33733205611000006\n"
"    },\n"
"    \"G\": {\n"
"      \"6\": 0.134999524776,\n"
"      \"9\": 0.3241039076,\n"
"      \"C\": 0.006655980175,\n"
"      \"R\": 0.00034199765000000003,\n"
"      \"%\": 0.10741169076000001,\n"
"      \"V\": 0.009587974095,\n"
"      \"A\": 0.029293907895000002,\n"
"      \"D\": 0.029399911552000002,\n"
"      \"g\": 0.21806516663999997\n"
"    },\n"
"    \"g\": {\n"
"      \"6\": 0.18409864176600002,\n"
"      \"9\": 0.065094573588,\n"
"      \"c\": 0.0038859896789999997,\n"
"      \"r\": 0.017719945560000002,\n"
"      \"#\": 0.050050856697,\n"
"      \"v\": 0.010277974546000001,\n"
"      \"a\": 0.065204806509,\n"
"      \"d\": 0.038309882628,\n"
"      \"G\": 0.15990053903999998\n"
"    }\n"
"  }\n"
"}\n"
;