#include <genesis.h>

#ifndef ATAN2_H
#define ATAN2_H

#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923

static const fix32 ATAN_LUT[256] = {
	FIX32(0.0000000000),FIX32(0.0039215485),FIX32(0.0078429764),FIX32(0.0117641631),FIX32(0.0156849881),FIX32(0.0196053309),
	FIX32(0.0235250710),FIX32(0.0274440882),FIX32(0.0313622624),FIX32(0.0352794736),FIX32(0.0391956019),FIX32(0.0431105278),
	FIX32(0.0470241318),FIX32(0.0509362949),FIX32(0.0548468980),FIX32(0.0587558227),FIX32(0.0626629506),FIX32(0.0665681638),
	FIX32(0.0704713446),FIX32(0.0743723758),FIX32(0.0782711405),FIX32(0.0821675224),FIX32(0.0860614053),FIX32(0.0899526737),
	FIX32(0.0938412126),FIX32(0.0977269074),FIX32(0.1016096438),FIX32(0.1054893085),FIX32(0.1093657884),FIX32(0.1132389710),
	FIX32(0.1171087446),FIX32(0.1209749978),FIX32(0.1248376255),FIX32(0.1286965013),FIX32(0.1325515323),FIX32(0.1364026044),
	FIX32(0.1402496096),FIX32(0.1440924408),FIX32(0.1479309912),FIX32(0.1517651553),FIX32(0.1555948280),FIX32(0.1594199049),
	FIX32(0.1632402828),FIX32(0.1670558588),FIX32(0.1708665312),FIX32(0.1746721990),FIX32(0.1784727620),FIX32(0.1822681208),
	FIX32(0.1860581771),FIX32(0.1898428334),FIX32(0.1936219929),FIX32(0.1973955598),FIX32(0.2011634395),FIX32(0.2049255380),
	FIX32(0.2086817623),FIX32(0.2124320205),FIX32(0.2161762215),FIX32(0.2199142752),FIX32(0.2236460927),FIX32(0.2273715857),
	FIX32(0.2310906672),FIX32(0.2348032511),FIX32(0.2385092525),FIX32(0.2422085871),FIX32(0.2459011721),FIX32(0.2495869254),
	FIX32(0.2532657662),FIX32(0.2569376146),FIX32(0.2606023917),FIX32(0.2642600199),FIX32(0.2679104224),FIX32(0.2715535237),
	FIX32(0.2751892491),FIX32(0.2788175253),FIX32(0.2824382800),FIX32(0.2860514417),FIX32(0.2896569404),FIX32(0.2932547070),
	FIX32(0.2968446734),FIX32(0.3004267728),FIX32(0.3040009393),FIX32(0.3075671084),FIX32(0.3111252164),FIX32(0.3146752558),
	FIX32(0.3182170002),FIX32(0.3217505544),FIX32(0.3252758042),FIX32(0.3287926915),FIX32(0.3323011594),FIX32(0.3358011520),
	FIX32(0.3392926145),FIX32(0.3427754932),FIX32(0.3462497357),FIX32(0.3497152904),FIX32(0.3531721069),FIX32(0.3566201360),
	FIX32(0.3600593294),FIX32(0.3634896400),FIX32(0.3669110217),FIX32(0.3703234297),FIX32(0.3737268255),FIX32(0.3771211497),
	FIX32(0.3805063771),FIX32(0.3838824615),FIX32(0.3872493632),FIX32(0.3906070437),FIX32(0.3939554653),FIX32(0.3972945915),
	FIX32(0.4006243869),FIX32(0.4039448169),FIX32(0.4072558481),FIX32(0.4105574480),FIX32(0.4138495853),FIX32(0.4171322295),
	FIX32(0.4204053512),FIX32(0.4236689219),FIX32(0.4269229141),FIX32(0.4301673014),FIX32(0.4334020581),FIX32(0.4366271598),
	FIX32(0.4398425828),FIX32(0.4430483044),FIX32(0.4462443029),FIX32(0.4494305575),FIX32(0.4526070482),FIX32(0.4557737560),
	FIX32(0.4589306629),FIX32(0.4620777516),FIX32(0.4652150058),FIX32(0.4683424102),FIX32(0.4714599501),FIX32(0.4745676117),
	FIX32(0.4776653824),FIX32(0.4807532499),FIX32(0.4838312032),FIX32(0.4868992318),FIX32(0.4899573263),FIX32(0.4930054778),
	FIX32(0.4960436784),FIX32(0.4990719209),FIX32(0.5020901990),FIX32(0.5050985071),FIX32(0.5080968402),FIX32(0.5110851942),
	FIX32(0.5140635659),FIX32(0.5170319525),FIX32(0.5199903521),FIX32(0.5229387636),FIX32(0.5258771863),FIX32(0.5288056206),
	FIX32(0.5317240673),FIX32(0.5346325278),FIX32(0.5375310045),FIX32(0.5404195003),FIX32(0.5432980185),FIX32(0.5461665634),
	FIX32(0.5490251398),FIX32(0.5518737530),FIX32(0.5547124091),FIX32(0.5575411147),FIX32(0.5603598769),FIX32(0.5631687036),
	FIX32(0.5659676030),FIX32(0.5687565842),FIX32(0.5715356566),FIX32(0.5743048302),FIX32(0.5770641155),FIX32(0.5798135236),
	FIX32(0.5825530662),FIX32(0.5852827553),FIX32(0.5880026035),FIX32(0.5907126240),FIX32(0.5934128303),FIX32(0.5961032364),
	FIX32(0.5987838570),FIX32(0.6014547069),FIX32(0.6041158015),FIX32(0.6067671569),FIX32(0.6094087892),FIX32(0.6120407151),
	FIX32(0.6146629519),FIX32(0.6172755171),FIX32(0.6198784285),FIX32(0.6224717045),FIX32(0.6250553640),FIX32(0.6276294258),
	FIX32(0.6301939095),FIX32(0.6327488350),FIX32(0.6352942223),FIX32(0.6378300921),FIX32(0.6403564651),FIX32(0.6428733625),
	FIX32(0.6453808058),FIX32(0.6478788169),FIX32(0.6503674179),FIX32(0.6528466311),FIX32(0.6553164793),FIX32(0.6577769856),
	FIX32(0.6602281731),FIX32(0.6626700655),FIX32(0.6651026865),FIX32(0.6675260602),FIX32(0.6699402110),FIX32(0.6723451634),
	FIX32(0.6747409422),FIX32(0.6771275725),FIX32(0.6795050796),FIX32(0.6818734889),FIX32(0.6842328261),FIX32(0.6865831172),
	FIX32(0.6889243882),FIX32(0.6912566655),FIX32(0.6935799756),FIX32(0.6958943450),FIX32(0.6981998008),FIX32(0.7004963699),
	FIX32(0.7027840796),FIX32(0.7050629571),FIX32(0.7073330300),FIX32(0.7095943260),FIX32(0.7118468729),FIX32(0.7140906986),
	FIX32(0.7163258312),FIX32(0.7185522990),FIX32(0.7207701302),FIX32(0.7229793534),FIX32(0.7251799971),FIX32(0.7273720900),
	FIX32(0.7295556609),FIX32(0.7317307387),FIX32(0.7338973524),FIX32(0.7360555311),FIX32(0.7382053040),FIX32(0.7403467003),
	FIX32(0.7424797493),FIX32(0.7446044805),FIX32(0.7467209234),FIX32(0.7488291075),FIX32(0.7509290624),FIX32(0.7530208178),
	FIX32(0.7551044035),FIX32(0.7571798492),FIX32(0.7592471847),FIX32(0.7613064400),FIX32(0.7633576449),FIX32(0.7654008294),
	FIX32(0.7674360235),FIX32(0.7694632573),FIX32(0.7714825607),FIX32(0.7734939638),FIX32(0.7754974968),FIX32(0.7774931897),
	FIX32(0.7794810727),FIX32(0.7814611759),FIX32(0.7834335294),FIX32(0.7853981634)
};

/**
 *  \brief
 *      Convert radians to degrees [0..360]
 *
 *  \param rad
 *      radians
 * 
 *  \return
 *      Degrees [0..360] converted from radians
 */
fix32 rad2deg(fix32 rad);

/**
 *  \brief
 *      Convert radians to SGDK value [0..1024], useful for SGDK sin-cos opertaions
 *
 *  \param rad
 *      radians
 * 
 *  \return
 *      Degrees [0..360] converted from radians, return value is an integer defined as [0..1024] range corresponding to radian [0..2PI] range
 */
fix32 rad2degSGDK(fix32 rad);

/**
 *  \brief
 *      The atan2() function returns a value in the range -PI to PI radians
 *
 *  \param y
 *      Y, usually the difference y2 - y1
 * 
 *  \param x
 *      X, usually the difference x2 - x1
 * 
 *  \return
 *      Degrees [0..360] converted from radians, return value is an integer defined as [0..1024] range corresponding to radian [0..2PI] range
 */
fix32 atan2LUTif(fix32 y, fix32 x);

#endif
