#ifndef RLS_H
#define RLS_H
struct RLS
{
    RLS();
    RLS(const RLS &rls)
    {
        latitude       = rls.latitude;
        longtitude     = rls.longtitude;
        elevationMin   = rls.elevationMin;
        elevationMax   = rls.elevationMax;
        azimuthMin     = rls.azimuthMin;
        azimuthMax     = rls.azimuthMax;
        rangeMin       = rls.rangeMin;
        rangeMax       = rls.rangeMax;
    }
    RLS(    double latitudeT,
            double longtitudeT,
            double elevationMinT,
            double elevationMaxT,
            double azimuthMinT,
            double azimuthMaxT,
            double rangeMinT,
            double rangeMaxT)
    {
         latitude       = latitudeT;
         longtitude     = longtitudeT;
         elevationMin   = elevationMinT;
         elevationMax   = elevationMaxT;
         azimuthMin     = azimuthMinT;
         azimuthMax     = azimuthMaxT;
         rangeMin       = rangeMinT;
         rangeMax       = rangeMaxT;
    }
    double latitude;
    double longtitude;
    double elevationMin;
    double elevationMax;
    double azimuthMin;
    double azimuthMax;
    double rangeMin;
    double rangeMax;
};
#endif // RLS_H
